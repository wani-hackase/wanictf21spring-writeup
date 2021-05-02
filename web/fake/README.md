# fake

## 問題文

偽物を見破れますか？

<https://fake.web.wanictf.org>

## フラグ

`FLAG{wow_y0u_h4ve_3po4ted_th3_7ake}`

## 解法

### ソースコード

ソースコードを見ると51行目に`style="display: none;"`と表示されないように設定されたリンクが見つかります。

```html
<a href="144c9defac04969c7bfad8efaa8ea194.html" style="display: none;">
  <button type="button" class="btn btn-primary">Link</button>
</a>
```

よって <https://fake.web.wanictf.org/144c9defac04969c7bfad8efaa8ea194.html> へアクセスするとフラグを取得できます。

### robots.txt

WebサーバーにはGoogleなどの検索エンジンに対して「どのページを検索結果に載せてほしいか・載せたくないか」を示すための`robots.txt`というファイルが設置されていることが多いです。

<https://fake.web.wanictf.org/robots.txt> には

```
User-Agent:*
Disallow:/144c9defac04969c7bfad8efaa8ea194.html
```

`/144c9defac04969c7bfad8efaa8ea194.html`というページを検索結果に載せないようにする設定がされていました。

よってこの隠しページへアクセスするとフラグを取得できます。

参考 : [Robots.txt の仕様 | Google Developers](https://developers.google.com/search/docs/advanced/robots/robots_txt?hl=ja)

### sitemap.xml

`sitemap.xml`はGoogleなどの検索エンジンに対して「サーバー上にどのようなコンテンツがあるか」を示すためのファイルです。

<https://fake.web.wanictf.org/sitemap.xml> には

```xml
<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="https://www.sitemaps.org/schemas/sitemap/0.9/">
  <url>
    <loc>index.html</loc>
  </url>
  <url>
    <loc>144c9defac04969c7bfad8efaa8ea194.html</loc>
  </url>
</urlset>
```

`/144c9defac04969c7bfad8efaa8ea194.html`というページがサーバー上に存在することが示されていました。

よってこの隠しページへアクセスするとフラグを取得できます。

参考 : [サイトマップの作成と送信 | Google Developers](https://developers.google.com/search/docs/advanced/sitemaps/build-sitemap?hl=ja)
