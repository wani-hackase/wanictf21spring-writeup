# manchester [com]
## 問題文

+ Manchester Encoding

## FLAG

```
FLAG{avoiding-consective-ones-and-zeros}
```

## 解法

ASKの正答者の83%の正答者だったので階段の設計としてはこの部分は悪くなかったかなと思っています。
ASKと同様の手順で31の連続した0 or 1を1つの0 or 1に置き換えるプログラムを書いたあと、Manchester Encodingの01 -> 1、10 -> 0の変換をしてデコードします。

`val_bins = next_bins[3:]`の部分はbitのアライメントが合わなかったので手作業でアライメントをかけた名残です。
せいぜい1～7bit分ずらせば正解にたどり着けます。

```
fp = open("./packet.csv", "r")

vals = fp.readlines()

count = 1
pre_val = 0
current = 0
sampling_rate = 31

val_bins = []

for i in range(len(vals)):
    pre_val = current
    current = int(vals[i])
    if current == pre_val:
        count = count + 1
    else:
        count = 1

    if count == sampling_rate:
        val_bins.append(pre_val)
        count = 1

pre_val = 0
current = 0
next_bins = []
for i in range(len(val_bins) // 2):
    b0 = val_bins[i * 2]
    b1 = val_bins[i * 2 + 1]
    if b0 == 1 and b1 == 0:
        next_bins.append(1)
    elif b0 == 0 and b1 == 1:
        next_bins.append(0)

val_bins = next_bins[3:]

c = 0
for i in range(len(val_bins)):
    val = int(val_bins[i])
    c = (c << 1) | val
    if i % 8 == 7:
        print(chr(c), end="")
        c = 0

print("")
```

Manchester符号なんてマイナーでしょ、と思う人もいるかもしれませんが、実は結構使われています。
今回の問題では答えが文字なので分かり辛かったのですが、実際のデータを送るときにASKを使っていると1が長く続きすぎてしまったり、0が長く続きすぎてしまったりしてどこからどこまでが1bitなのか分からなくなってしまうことが生じます。
無線の受信機も、例えば0が長く続いて電波が無い状態も長く続くと回路的にうまく動かなくなってしまう場合も生じます。
なので無線通信的には、常に1と0が変化して動いている方が1bitの境目も分かりやすくなります(シンボルタイミング同期がとりやすいです)し、無線回路的にも安定動作しやすくなるというわけでManchester符号で頻繁に1と0が切り替わるようにすることが多いです。
