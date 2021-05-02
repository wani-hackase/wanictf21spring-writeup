# Can't restore the flag?

## 問題文

ちりつもですよ

```
nc crt.cry.wanictf.org 50000
```

## フラグ

`FLAG{Ch1n3s3_r3m@1nd3r_7h30r3m__so_u5eful}`

## 解法
この問題では 指定した mod での flag の値が返されます。    
指定できる値が大きくないため、直接 flag を出力することはできません（実はできます）が、複数の mod での flag の値を利用して、 Chinese remainder theorem から flag の値を復元することができます。  
複数の mod での値から flag を実際に求めるときは Garner's Algorithm で復元することができます。  


> 実は直接 flag を出力することもできて、mod の上限だけしか設定していないために十分小さな負のmosを指定してやることで flag を直接表示することもできます。（非想定解でした）
