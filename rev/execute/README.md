# execute

## 問題文

コマンドを間違えて、ソースコードも消しちゃった！

今残っているファイルだけで実行して頂けますか？

(reverse engineeringすれば、実行しなくても中身は分かるみたいです。)

## フラグ

`FLAG{c4n_y0u_execu4e_th1s_fi1e}`

## 解法

### 解法1 実行ファイルを作成する

ソースコードから実行ファイルを作成するには複数のステップが必要です。

```
main.c ソースコード

↓      コンパイル

main.s アセンブリファイル

↓      アセンブル

main.o オブジェクトファイル

↓      リンク

main   実行ファイル
```

この問題ではアセンブリファイル `main.s` と共有ライブラリ `libprint.so` が与えられます。

なので

1. `main.s` からオブジェクトファイル `main.o` を作成する

2. 共有ライブラリと一緒にリンクして実行ファイルを作成する

となります。

```
$ as -o main.o main.s
$ gcc -o main main.o -I./ -L./ -lprint
$ export LD_LIBRARY_PATH=$(pwd) ; ./main
```

```
Flag is "FLAG{c4n_y0u_execu4e_th1s_fi1e}"
```

### 解法2 reverse engineeringする

`main.s` の処理を確認します。18行目から

```
	movabsq	$7941081424088616006, %rax
	movabsq	$7311705455698409823, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movabsq	$3560223458505028963, %rax
	movabsq	$35295634984951667, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print@PLT
```

という処理があります。複数の値を `movabsq` 命令でレジスターに格納したあと、`movq` 命令でスタックへ入れています。

リトルエンディアンであることに注意してスタックの中身を再現すると

```python
from Crypto.Util.number import *

ans = long_to_bytes(7941081424088616006)[::-1]
ans += long_to_bytes(7311705455698409823)[::-1]
ans += long_to_bytes(3560223458505028963)[::-1]
ans += long_to_bytes(35295634984951667)[::-1]

print(ans)
# FLAG{c4n_y0u_execu4e_th1s_fi1e}
```

フラグが取得できます。実行ファイルを実行したときには、このフラグ文字列を共有ライブラリ `libprint.so` 内のprint関数で画面へ表示します。
