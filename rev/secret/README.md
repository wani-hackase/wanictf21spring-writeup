# secret

## 問題文

この問題では Linux の ELF 実行ファイル(バイナリ)である「secret」が配布されています。

このバイナリを実行すると `secret key` を入力するように表示されます。

試しに「abcde」と入力してみると「Incorrect」と言われました。

```
$ file secret
secret: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=1daf4ab43cfa357911806c3ccae34a1b6e027913, for GNU/Linux 3.2.0, not stripped

$ sudo chmod +x secret

$ ./secret
...
Input secret key : abcde
Incorrect

$ ./secret
...
Input secret key : ??????
Correct! Flag is ??????
```

このバイナリが正しいと判断する `secret key` を見つけて読み込んでみましょう！

(`secret key` とフラグは別の文字列です)

(このファイルを実行するためには Linux 環境が必要となりますので WSL や VirtualBox で用意してください)

ヒント :「表層解析」や「静的解析」を行うことで `secret key` が見つかるかも...?

表層解析ツール [strings](https://linux.die.net/man/1/strings)

静的解析ツール [Ghidra](https://ghidra-sre.org/)

## フラグ

`FLAG{ana1yze_4nd_strin6s_and_execu7e_6in}`

## 解法

まずはバイナリ解析の基本、表層解析ツール strings でバイナリに含まれる文字列を抽出します

```
$ strings secret
/lib64/ld-linux-x86-64.so.2
libc.so.6
...
Input secret key :
Incorrect
wani_is_the_coolest_animals_in_the_world!
Correct! Flag is %s
...
```

バイナリを実行したときに出力される文字列たち(Incorrectなど)とともに「wani_is_the_coolest_animals_in_the_world!」という文字列が出てきました

次はバイナリの処理を確認するために静的解析を Ghidra で行います

バイナリを読み込み、「Symbol Tree」から`_start`関数を選択します

```cpp
void _start(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000000;
  undefined auStack8 [8];

  __libc_start_main(main,in_stack_00000000,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_3,
                    auStack8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
```

main関数が出てきたのでクリックして調べます

そしてDecompile画面にて右クリック -> Rename Variableで変数名を変更して読みやすくします

```cpp
undefined8 main(void)

{
  int secretkey_cmp_result;
  size_t input_length;
  undefined8 return;
  undefined4 flag_seed [44];
  byte flag [41];
  undefined local_4f;
  byte input [56];
  ulong i;

  flag_seed[0] = 0x31;
  flag_seed[1] = 0x2d;
  flag_seed[2] = 0x2f;
  flag_seed[3] = 0x2e;
  flag_seed[4] = 0x24;
  flag_seed[5] = 8;
  flag_seed[6] = 0x1d;
  flag_seed[7] = 0x3e;
  flag_seed[8] = 0x45;
  flag_seed[9] = 0x11;
  flag_seed[10] = 0x1f;
  flag_seed[11] = 0x3a;
  flag_seed[12] = 0x3c;
  flag_seed[13] = 0x5b;
  flag_seed[14] = 1;
  flag_seed[15] = 8;
  flag_seed[16] = 0x3a;
  flag_seed[17] = 0;
  flag_seed[18] = 0;
  flag_seed[19] = 0x2d;
  flag_seed[20] = 8;
  flag_seed[21] = 0;
  flag_seed[22] = 0x5f;
  flag_seed[23] = 0x1e;
  flag_seed[24] = 0x3e;
  flag_seed[25] = 0xd;
  flag_seed[26] = 0x1d;
  flag_seed[27] = 0x3b;
  flag_seed[28] = 0x36;
  flag_seed[29] = 0xb;
  flag_seed[30] = 0x27;
  flag_seed[31] = 0x11;
  flag_seed[32] = 0xb;
  flag_seed[33] = 0x10;
  flag_seed[34] = 0x68;
  flag_seed[35] = 0x12;
  flag_seed[36] = 0x30;
  flag_seed[37] = 0x44;
  flag_seed[38] = 5;
  flag_seed[39] = 10;
  flag_seed[40] = 0x5c;
  show_description();
  printf("Input secret key : ");
  __isoc99_scanf(&DAT_001022cf,input);
  input_length = strlen((char *)input);
  if (input_length == 0x29) {
    secretkey_cmp_result = strncmp((char *)input,"wani_is_the_coolest_animals_in_the_world!",0x29);
    if (secretkey_cmp_result == 0) {
      i = 0;
      while (i < 0x29) {
        flag[i] = input[i] ^ (byte)flag_seed[i];
        i = i + 1;
      }
      local_4f = 0;
      printf("Correct! Flag is %s\n",flag);
      return = 0;
    }
    else {
      puts("Incorrect");
      return = 1;
    }
  }
  else {
    puts("Incorrect");
    return = 1;
  }
  return return;
}
```

入力文字列が`wani_is_the_coolest_animals_in_the_world!`と等しい場合、入力文字列とflag_seedを1文字ずつXORしてフラグを生成し出力する処理をしていることがわかります

よって `secret key` は「wani_is_the_coolest_animals_in_the_world!」だと判明しました

実際にバイナリを実行してみると

```
$ ./secret

   ▄▀▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▀▀█▀▀▄
  █ █   ▐ ▐  ▄▀   ▐ █ █    ▌ █   █   █ ▐  ▄▀   ▐ █    █  ▐
     ▀▄     █▄▄▄▄▄  ▐ █      ▐  █▀▀█▀    █▄▄▄▄▄  ▐   █
  ▀▄   █    █    ▌    █       ▄▀    █    █    ▌     █
   █▀▀▀    ▄▀▄▄▄▄    ▄▀▄▄▄▄▀ █     █    ▄▀▄▄▄▄    ▄▀
   ▐       █    ▐   █     ▐  ▐     ▐    █    ▐   █
           ▐        ▐                   ▐        ▐

Input secret key : wani_is_the_coolest_animals_in_the_world!
Correct! Flag is FLAG{ana1yze_4nd_strin6s_and_execu7e_6in}
```

フラグ `FLAG{ana1yze_4nd_strin6s_and_execu7e_6in}` を取得できました
