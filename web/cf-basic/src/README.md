# cf-basic(src)
* exceptionとcf-basicのsrc

## deploy方法

### 事前準備
* Route53でホストゾーンを作成する
* ACMでdeploy先のdomainの証明書を取得する
  * かならず`us-east-1`で取得する
* [poetry](https://github.com/python-poetry/poetry)をinstall
* `poetry`でライブラリを仮想環境にインストール
```sh
poetry install
```
### deploy
* `sam-cli`でbuild
```sh
poetry run sam build
```
* `sam-cli`でdeploy
  * ガイドに従ってパラメータを指定
  * regionはus-east-1固定
  * FLAG1はexceptionのFLAG
  * FLAG2はcf-basicのFLAG
  * `XXXFunction may not have authorization defined, Is this okay?`はyes
  * `Deploy this changeset? [y/N]:`が出たらy
  * 待てば勝手にdeployされる
```
$ poetry run sam deploy --guided

Configuring SAM deploy
======================

        Looking for config file [samconfig.toml] :  Not found

        Setting default arguments for 'sam deploy'
        =========================================
        Stack Name [sam-app]: cf-basic
        AWS Region [us-east-1]: us-east-1
        Parameter FLAG1 []: FAKE{1}
        Parameter FLAG2 []: FAKE{2}
        Parameter BucketName []: cf-basic
        Parameter HostedZoneName []: hoge.com
        Parameter CloudFrontDomainName []: cf-basic.hoge.com
        Parameter AcmCertificateArn []: arn:aws:acm:us-east-1:xxxxx:certificate/yyyyy
        #Shows you resources changes to be deployed and require a 'Y' to initiate deploy
        Confirm changes before deploy [y/N]: y
        #SAM needs permission to be able to create roles to connect to the resources in your template
        Allow SAM CLI IAM role creation [Y/n]: y
        HelloFunction may not have authorization defined, Is this okay? [y/N]: y
        AdminFunction may not have authorization defined, Is this okay? [y/N]: y
        Save arguments to configuration file [Y/n]: y
        SAM configuration file [samconfig.toml]:
        SAM configuration environment [default]:

```
* frontをS3に配置
```
aws s3 sync front/ s3://<BucketName>/
```
