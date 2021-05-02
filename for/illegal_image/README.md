# secret_image

## 問題文
裏で画像がやり取りされているらしい

## フラグ

`FLAG{ICMP_Exfiltrate_image}`

## 解法

配布されているpcapファイルをwiresharkで開いて眺めると、401 bytesという明らかに大きいICMPパケットが多数あります。

![](https://i.imgur.com/uzqjiUK.png)

ICMPの機能の1つとしてpingがありますが、
```
$ ping 8.8.8.8
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=117 time=8.57 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=117 time=4.93 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=117 time=9.84 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=117 time=14.1 ms
^C
--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3003ms
rtt min/avg/max/mdev = 4.931/9.360/14.099/3.276 ms
```
のように30～60bytes程度の物です。

そこで一つ目のICMPパケットを見ると`ff d8`というJPGのイメージ開始マーカがあります。
問題名も考慮してここが怪しいとなってもらえれば、解法に繋がると思います。

この問題では、ICMPパケットのデータ部分をつなげていけばFLAG画像が復元されます。
この手法は`ICMP exfiltration`と呼ばれるICMPパケットのデータ部に任意のデータを埋め込む手法です。


2系で申し訳ないですが、以下に解答例のスクリプトを記載しておきます。
```
from scapy.all import *

packets = rdpcap('illegal_image.pcap')

data = ''
for p in packets:
    if p.haslayer(ICMP):
        if p[IP].src == '192.168.0.133':
            data += p[Raw].load

with open('flag.jpg', 'wb') as f:
    f.write(data)
```

