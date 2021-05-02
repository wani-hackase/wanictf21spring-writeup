# netcat [pwn]
## 問題文

```
nc netcat.pwn.wanictf.org 9001
```

+ netcat (nc)と呼ばれるコマンドを使うだけです。
+ つないだら何も出力されなくても知っているコマンドを打ってみましょう。

### 使用ツール例
+ [netcat (nc)](https://github.com/wani-hackase/memo-setup-pwn-utils#netcat)

### gccのセキュリティ保護

+ Full RELocation ReadOnly (RELRO)
+ Stack Smash Protection (SSP)有効
+ No eXecute bit(NX)有効
+ Position Independent Executable (PIE)有効

## FLAG

```
FLAG{this_is_the_same_netcat_problem_as_previous_one}
```

## 解法

ncで接続して`cat flag.txt`を入力するとflagの中身が見れます。
これは多くの人が解いていたので大丈夫かと思います。
