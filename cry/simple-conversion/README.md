# 問題名  
Simple conversion
## 問題文  
戻し方を忘れました…

## フラグ  
`FLAG{7h1s_i5_h0w_we_c0nvert_m3ss@ges_1nt0_num63rs}`

## 解法
Crypto 問では特に多く見られますが、文字列を整数として扱いたい場面がしばしばあります。  
ここではその変換の一例として、`int.from_bytes` を用いて flag を整数に変換しています。  
この処理の逆の操作は、`int.to_bytes` で可能です。これを利用すると  
```
flag.to_bytes((flag.bit_length() + 7 // 8), byteorder='big')
```
とすることで元の flag が復元できます。  
  
この方法や `struct.pack`, `struct.unpack` を利用する方法などは、組み込みのメソッドで完結するというメリットがあります。  
また、Crypto問で頻繁に用いられるライブラリ pycrypto (pycryptodome) の Crypto.Util.number にある`bytes_to_long`, `long_to_bytes` も頻繁に用いられます。  
基本的に変換の処理は公開されていると思うので、`struck.pack` なら `struck.unpack`, `long_to_bytes` なら `bytes_to_long` というように、対応するメソッドで逆変換すると確実です。  

解法スクリプト: [solve.py](solver/solve.py)  





