# exception

## 問題文
API Gateway, Lambda, S3, CloudFront, CloudFormationを使ってアプリを作ってみました。

<https://exception.web.wanictf.org/>

## フラグ

`FLAG{b4d_excep7ion_handl1ng}`

## 解法
* `hello.py`を確認すると、例外を発生させるとFlagが返ってくることが分かる
* `name`にString以外のものを送信すると例外が発生する
  * `hello.py`では、最初のほうに`json.loads(event["body"])`と記述があるため、JSON形式で送信しなければならない
```
# curlでの例
curl -X POST https://cf-basic.web.wanictf.org/hello -d '{"name":1}'
```
* AWSの構成は`cf-basic`の方に記述してあります
