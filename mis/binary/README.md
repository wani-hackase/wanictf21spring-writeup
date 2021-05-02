# binary [com]
## 問題文

+ 文字も所詮1と0の集合です。
+ sample.pyを参考に復号器を作ってみてください。

## FLAG

```
FLAG{the_basic_knowledge_of_communication}
```

## 解法

### はじめに

フラグの文字列をバイナリにして2進数にしているだけなので逆に1bitずつつめてchar型に変換しながら出力するだけです。

```
fp = open("./binary.csv", "r")

vals = fp.readlines()

c = 0
for i in range(len(vals)):
    val = int(vals[i])
    c = (c << 1) | val
    if i % 8 == 7:
        print(chr(c), end="")
        c = 0

print("")
```


### 解説

binary、ASK、Manchesterはsaruの専門であるネットワークのなかの、さらにワイヤレスネットワークの部分を解析する楽しさを味わってほしいと思って作りました。
実際にsaruはUSRPなどのソフトウェア無線機を使って某ネット通販大手で売られている激安後付けの車用の何かのプロトコルを電波から解析したりして、あー、こりゃ絶対買わない方がいいなとか思ったりしてます。
その作業が結構楽しいので、そういう技術が身に付く問題を作りたいなーと思ったのがbinary、ASK、Manchesterです。

が、Pwnに引き続いて難易度レベルの階段の設計がうまく行かなかったです。2021/05/02 18:35時点で
1. binary 185 solved
2. ASK 49 solved 26%
3. Manchester 41 solved 83%

という結果で、なんとASKがbinaryの26%の正答者しか出ないという。
いろいろこの間を埋める問題が必要だったなと反省しています。
ワイヤレスネットワークの問題はこれに懲りず、次回も初心者が学べる良い問題を作るのにトライしたいと思ってます。

