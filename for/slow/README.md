# slow

## 問題文

宇宙からメッセージが届きました。(※音量注意！)

## フラグ

`FLAG{encoded_by_slow-scan_television}`

## 解法

Forensicsのwav問題では比較的頻出sstv(Slow Scan TV)問題です。
ﾋﾟﾋﾟｰｶﾞｶﾞｰみたいなwavが特徴です。

初めての人にもタイトルとか拡張子とかから検索して、解法にたどり着いて貰いえたらなーと思っている問題です。
sstvにたどり着いたら[qsstv](https://ourcodeworld.com/articles/read/956/how-to-convert-decode-a-slow-scan-television-transmissions-sstv-audio-file-to-images-using-qsstv-in-ubuntu-18-04)や[RX-SSTV](http://rxsstv.cqsstv.com/)など、いろんなdecoderにたどり着けるかなと思います。

僕が初めて解いたときに使ったのはqsstvなんですが、画像が出来ていく様が不思議ですごくウキウキした記憶があります。
解いた経験がない方は、なんだか楽しいので是非やってみてください。

ですが、qsstvは色々と環境を整えないといけないので、今回はコマンドラインからサクッと解けるdecoderを紹介しておきます。
[SSTV Decoder](https://github.com/colaclanth/sstv)を使えば環境を色々と整えることもなく、なんの感動もなく、この問題を解くことができます。

```
$ sstv -d slow.wav -o result.png
```