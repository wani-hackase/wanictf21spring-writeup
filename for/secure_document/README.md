# secure_document

## 問題文

本日の資料は以下を入力して圧縮しました。
```
the password for today is nani
```

## フラグ

`FLAG{Nani!very_strong_password!}`

## 解法

`file.zip`を解凍すると、暗号化された`flag_20210322.zip`と`password_generator`がでます
もちろんflag.zipは`nani`では解凍できないので、password_generatorの中身を確認していきます

一目見てautohotkeyのファイルだと気付いた人は実際に使ってやるととても楽だと思います。
気付かなかった人も"FormatTime"とか"SendInput"とかの特徴的な部分を組み合わせて検索してAutoHotkeyにたどり着いてもらったり、`password_generator`の中身からなんらかの入力補助であることを推測して調べてもらったり．．．と経験的には思っていたのですが、かなりエスパー気味になっていたみたいです。

反省はここまでにして、手作業で追った場合の文字列を追っていきます。

入力するのは
```
the password for today is wani
```
です。

theを入力すると、
```
::the::
Send, +wani
return
```
から、`Wani`が入力されます。


そこにpasswordを入力すると、
```
::password::
Send, +c+t+f
return
```
から、`WaniCTF`が入力されます。


そこにforを入力すると、
```
::for::
Send, {home}{right 3}{del}1{end}{left 2}{del}7
return
```
から、`{home}{right 3}{del}1`で左から3番目の文字が一文字消されて、1が入力されます。
さらに、`{end}{left 2}{del}7`で右から2番目の文字が一文字消されて、7が入力されます。
この段階で入力されている文字列は`Wan1C7F`です。


そこにtodayを入力すると、
```
::today::
FormatTime , x,, yyyyMMdd
SendInput, {home}{right 4}_%x%
return
```
から、`_yyyyMMdd`の形で左から四文字目に続く位置に日付が入力されます。
writeupを用意している本日は2021年5月1日なので、以下のように入力しておきます。
この段階で入力されている文字列は`Wan1_20210501C7F`です。


続いてisを入力すると、
```
::is::
Send, _{end}{!}{!}{left}
return
```
から、日付のあとに"_"が入力された後に右端に"!"を2つ、カーソルを1つ左に送ります。
この段階で入力されている文字列は`Wan1_20210501_C7F!!`です。


最後にnaniを入力すると、
```
:*?:ni::
Send, ^a^c{Esc}{home}password{:} {end}
```
から、naが入力された後にパスワードのコピーが行われます。
入力されている文字列は`password: Wan1_20210501_C7F!na!`です。


ファイル名から[date]部分は`20210428`であると推定されるので、zipのpasswordは`Wan1_20210428_C7F!na!`の形になります。
これでzipを解凍すれば、flagが手に入ります。