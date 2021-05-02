# timer

## 問題文

フラグが出てくるまで待てますか？

`super_complex_flag_print_function` 関数でフラグを表示しているようですが、難読化されているため静的解析でフラグを特定するのは難しそうです...

GDBを使って動的解析してみるのはいかがでしょうか？

## フラグ

`FLAG{S0rry_Hav3_you_b3en_wai7ing_lon6?_No_I_ju5t_g0t_her3}`

## 解法

実行してみると1秒ずつ経過していくごとに残り秒数が減っていき、0秒になるとフラグを表示するようです。

ただこのままフラグが表示されるまで待つと大会が終わってしまいます。

なのでデバッガーを使って「1秒ずつ減っていくタイマー処理」を飛ばして「フラグを表示する処理」を実行することでフラグを入手します。

実行ファイルを読み込んでGDBを起動します。(このGDBには[peda](https://github.com/longld/peda)を導入しています)

```
$ gdb timer
```

main関数をディスアセンブルしてどのような動作なのか簡単に確認します。

```
gdb-peda$ start
...
gdb-peda$ disas main
Dump of assembler code for function main:
=> 0x00005555555554ef <+0>:	endbr64
   0x00005555555554f3 <+4>:	push   rbp
   0x00005555555554f4 <+5>:	mov    rbp,rsp
   0x00005555555554f7 <+8>:	call   0x55555555541a <show_description>
   0x00005555555554fc <+13>:	call   0x55555555549d <timer>
   0x0000555555555501 <+18>:	call   0x555555555170 <super_complex_flag_print_function>
   0x0000555555555506 <+23>:	mov    eax,0x0
   0x000055555555550b <+28>:	pop    rbp
   0x000055555555550c <+29>:	ret
End of assembler dump.
```

`0x00005555555554f7`で`show_description`関数、`0x00005555555554fc`で`timer`関数、`0x0000555555555501`で`super_complex_flag_print_function`関数を呼んでいるようです。

`timer`関数にブレークポイント(指定した命令の箇所で実行を一時停止する機能)を貼って実行してみます。

```
gdb-peda$ b *0x00005555555554fc
Breakpoint 2 at 0x5555555554fc
gdb-peda$ run
Starting program: /vagrant/chal2021/timer/file/timer

  ████████╗██╗███╗   ███╗███████╗██████╗
  ╚══██╔══╝██║████╗ ████║██╔════╝██╔══██╗
     ██║   ██║██╔████╔██║█████╗  ██████╔╝
     ██║   ██║██║╚██╔╝██║██╔══╝  ██╔══██╗
     ██║   ██║██║ ╚═╝ ██║███████╗██║  ██║
     ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝

I'll show the flag when the timer is 0 seconds.

[----------------------------------registers-----------------------------------]
RAX: 0x1
RBX: 0x555555555510 (<__libc_csu_init>:	endbr64)
RCX: 0x7ffff7ede1e7 (<__GI___libc_write+23>:	cmp    rax,0xfffffffffffff000)
RDX: 0x0
RSI: 0x5555555592a0 ("\n'll show the flag when the timer is 0 seconds.\n\235╚══════╝╚═╝  ╚═╝\n\226\210║\n╗\n\220═██╗\n")
RDI: 0x7ffff7fbb4c0 --> 0x0
RBP: 0x7fffffffe370 --> 0x0
RSP: 0x7fffffffe370 --> 0x0
RIP: 0x5555555554fc (<main+13>:	call   0x55555555549d <timer>)
R8 : 0x1
R9 : 0x7c ('|')
R10: 0x7ffff7fb8be0 --> 0x5555555596a0 --> 0x0
R11: 0x246
R12: 0x555555555080 (<_start>:	endbr64)
R13: 0x7fffffffe460 --> 0x1
R14: 0x0
R15: 0x0
EFLAGS: 0x246 (carry PARITY adjust ZERO sign trap INTERRUPT direction overflow)
[-------------------------------------code-------------------------------------]
   0x5555555554f3 <main+4>:	push   rbp
   0x5555555554f4 <main+5>:	mov    rbp,rsp
   0x5555555554f7 <main+8>:	call   0x55555555541a <show_description>
=> 0x5555555554fc <main+13>:	call   0x55555555549d <timer>
   0x555555555501 <main+18>:	call   0x555555555170 <super_complex_flag_print_function>
   0x555555555506 <main+23>:	mov    eax,0x0
   0x55555555550b <main+28>:	pop    rbp
   0x55555555550c <main+29>:	ret
No argument
[------------------------------------stack-------------------------------------]
0000| 0x7fffffffe370 --> 0x0
0008| 0x7fffffffe378 --> 0x7ffff7df40b3 (<__libc_start_main+243>:	mov    edi,eax)
0016| 0x7fffffffe380 --> 0x7ffff7ffc620 --> 0x5045e00000000
0024| 0x7fffffffe388 --> 0x7fffffffe468 --> 0x7fffffffe6b0 ("/vagrant/chal2021/timer/file/timer")
0032| 0x7fffffffe390 --> 0x100000000
0040| 0x7fffffffe398 --> 0x5555555554ef (<main>:	endbr64)
0048| 0x7fffffffe3a0 --> 0x555555555510 (<__libc_csu_init>:	endbr64)
0056| 0x7fffffffe3a8 --> 0x880c8a2b7bbbedec
[------------------------------------------------------------------------------]
Legend: code, data, rodata, value

Breakpoint 2, 0x00005555555554fc in main ()
```

`timer`関数を呼ぶ手前で停止しました。もしここで実行を再開する`continue`コマンドを入力すると以下のように`timer`関数のタイマーが実行されます。

```
gdb-peda$ c
Continuing.
259200 seconds left.
259199 seconds left.
259198 seconds left.
```

さて、GDBには任意の箇所から実行できる`jump`コマンドというものがあります。現在`timer`関数を呼ぶ手前で停止しています。ここで`super_complex_flag_print_function`関数を呼ぶ箇所のアドレス`0x0000555555555501`を`jump`コマンドで指定すると、`timer`関数を実行せずに`super_complex_flag_print_function`関数の処理を実行できます。

先程貼ったブレークポイントの箇所で止まったら`jump`コマンドを実行してみると

```
gdb-peda$ j *0x0000555555555501
Continuing at 0x555555555501.
The time has come. Flag is "FLAG{S0rry_Hav3_you_b3en_wai7ing_lon6?_No_I_ju5t_g0t_her3}"
[Inferior 1 (process 109513) exited normally]
Warning: not running
```

タイマー部分を飛ばしてフラグを表示させることができました。

フラグは`FLAG{S0rry_Hav3_you_b3en_wai7ing_lon6?_No_I_ju5t_g0t_her3}`、「ごめん、待った？」「ううん、今来たところ」でした。

### 別解

呼び出す関数のアドレスを格納するRIPレジスタに`super_complex_flag_print_function`を指定するとフラグを取得することがきでます。

```
gdb-peda$ start
gdb-peda$ set $rip=0x0000555555555501
gdb-peda$ c
Continuing.
The time has come. Flag is "FLAG{S0rry_Hav3_you_b3en_wai7ing_lon6?_No_I_ju5t_g0t_her3}"
```
