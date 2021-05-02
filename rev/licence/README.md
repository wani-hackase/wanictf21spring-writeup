# licence

## 問題文

このプログラムは非常に強力なライセンス確認処理が実装されています。

ただ、今持っているライセンスファイルは間違っているようです。

正しいライセンスファイルを見つけて頂けますか？

```
$ ./licence key.dat
Failed to activate.
```

複雑な処理をシンボリック実行で解析してくれるツール「angr」を使えば簡単に解けるかも。

## フラグ

`FLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}`

## 解法

コマンドライン引数にファイル名を与えて実行すると、そのファイルが正しいライセンスファイルか確かめてくれるバイナリのようです。

まずはGhidraを使って処理を確認していきます。

```cpp

undefined8 main(int param_1,long param_2)

{
  int ret_check;
  undefined8 ret;
  FILE *fp;
  char *readline;
  long in_FS_OFFSET;
  char licence_L3 [32];
  char licence_L1 [32];
  char licence_L2 [72];
  long canary;

  canary = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 2) {
    fp = fopen(*(char **)(param_2 + 8),"r");
    if (fp == (FILE *)0x0) {
      puts("Failed to open file");
      ret = 1;
    }
    else {
      readline = fgets(licence_L1,0x1d,fp);
      if (readline == (char *)0x0) {
        puts("Failed to read file");
        ret = 1;
      }
      else {
        ret_check = strcmp(licence_L1,"-----BEGIN LICENCE KEY-----\n");
        if (ret_check == 0) {
          readline = fgets(licence_L2,0x41,fp);
          if (readline == (char *)0x0) {
            puts("Failed to read file");
            ret = 1;
          }
          else {
            ret_check = check(licence_L2);
            if (ret_check == 0) {
              readline = fgets(licence_L3,0x1b,fp);
              if (readline == (char *)0x0) {
                puts("Failed to read file");
                ret = 1;
              }
              else {
                ret_check = strcmp(licence_L3,"-----END LICENCE KEY-----\n");
                if (ret_check == 0) {
                  fclose(fp);
                  puts("Correct! This software is successfully activated!");
                  ret = 0;
                }
                else {
                  puts("Failed to activate.");
                  ret = 1;
                }
              }
            }
            else {
              puts("Failed to activate.");
              ret = 1;
            }
          }
        }
        else {
          puts("Failed to activate.");
          ret = 1;
        }
      }
    }
  }
  else {
    puts("Failed to execute. Usage: ./licence <key file name>");
    ret = 1;
  }
  if (canary != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ret;
}
```

処理の流れは

- コマンドライン引数で与えたファイルをfopenする
- 1行目をfgetsして`"-----BEGIN LICENCE KEY-----\n"`と等しいか比較する
- 2行目をfgetsしてcheck関数で処理する
- 3行目をfgetsして`"-----END LICENCE KEY-----\n"`と等しいか比較する

となっています。

そしてcheck関数は

```cpp
undefined8 check(byte *param_1)

{
  undefined8 uVar1;

  if ((param_1[0xb] ^ *param_1) == 0x7e) {
    uVar1 = 1;
  }
  else {
    if ((int)(char)param_1[0x2d] + (int)(char)*param_1 == 0x80) {
      uVar1 = 1;
    }
    else {
      if ((int)(char)*param_1 - (int)(char)param_1[0x1c] == 0x18) {
        uVar1 = 1;
      }
      else {
        if (*param_1 == 0x46) {
          if ((int)(char)param_1[1] - (int)(char)param_1[0xd] == 0x1a) {
            uVar1 = 1;
          }
          else {
            if ((int)(char)param_1[1] - (int)(char)param_1[0x12] == 0x21) {
              uVar1 = 1;
            }
            else {
              if ((param_1[0x11] ^ param_1[1]) == 0x34) {
                uVar1 = 1;
              }
              else {
                if ((int)(char)param_1[1] - (int)(char)*param_1 == 6) {
                  if ((int)(char)param_1[2] - (int)(char)param_1[9] == -0x1c) {
                    uVar1 = 1;
                  }
                  else {
```

と長大な処理で文字列比較をしているようです。この処理を一つ一つ追っていってもいいのですが時間がかかりそうなので[angr](https://angr.io/)を使います。

angrはシンボリック実行を用いるバイナリ解析ツールで、バイナリの中で行われている演算や条件分岐などの処理を解析することで与えられた条件を満たす入力値を特定します。

このバイナリの場合は、main関数内の `puts("Correct! This software is successfully activated!");` という処理に到達する入力ファイルを特定します。

到達したいアドレス・到達してほしくないアドレスを調べ、以下のようなスクリプトを作成し実行します。

> angrは基本となるアドレスが0x400000なのでGhidraで0x105E6Dと表示されているアドレスは0x405E6Dと指定します。

```python
import angr
import claripy

proj = angr.Project("./licence")

# シンボリックファイルの定義
filename = "key.dat"
data = claripy.BVS("data", 128 * 8)
simfile = angr.SimFile(filename, content=data)

# コマンドライン引数 "key.dat" を指定して、定義したシンボリックファイルを読み込む
state = proj.factory.entry_state(
    args=["./licence", "key.dat"],
    fs={filename: simfile},
)
simgr = proj.factory.simulation_manager(state)

# 到達したいアドレス、到達してほしくないアドレスを指定する
simgr.explore(find=0x405E6D, avoid=0x405E4B)

# 結果を表示する
try:
    solution = simgr.found[0]
    print(solution.posix.dump_file_by_path(filename))
except IndexError:
    print("Not Found")

"""
b'-----BEGIN LICENCE KEY-----\nFLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}\n-----END LICENCE KEY-----\n\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
"""
```

2分程度で正しいライセンスファイルの中身

```
-----BEGIN LICENCE KEY-----
FLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}
-----END LICENCE KEY-----
```

が特定でき、フラグ `FLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}` を取得できました。

(参考) シンボリックファイルの定義についてはangrが解析時に勝手に行ってくれるので以下のような簡略化したスクリプトでもフラグを取得可能です。

```python
import angr

proj = angr.Project("./licence")
state = proj.factory.entry_state(args=["./licence", "key.dat"])
simgr = proj.factory.simulation_manager(state)
simgr.explore(find=0x405E6D, avoid=0x405E4B)

try:
    solution = simgr.found[0]
    print(solution.posix.dump_file_by_path("key.dat"))
except IndexError:
    print("Not Found")
```
