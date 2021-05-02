# git_master
## 問題文

<https://hub.docker.com/r/wanictf21spring/nginx_on_ubuntu>

ホームページをみんなで開発したいので、イメージを公開するです。

昔、秘密の文字列をコミットしたことがあるけど大丈夫だよね...？

## FLAG

```
FLAG{y0u_4r3_p3rf3c7_g1t_m45t3r}
```

## 解法

コンテナをプルして起動

```
$ docker pull wanictf21spring/nginx_on_ubuntu
$ docker run -it wanictf21spring/nginx_on_ubuntu bash
```

中に入ってディレクトリ移動

```
# cd /var/www/html/
root@2d644ad86d29:/var/www/html# ls -al
total 52
drwxr-xr-x 1 root root  4096 Apr 13 04:39 .
drwxr-xr-x 1 root root  4096 Apr 13 04:57 ..
-rw-r--r-- 1 root root    10 Apr 13 04:39 Flag.txt
drwxr-xr-x 6 root root  4096 Apr 13 01:07 assets
-rw-r--r-- 1 root root 17542 Apr 13 01:07 favicon.ico
-rw-r--r-- 1 root root  9365 Apr 13 00:01 index.html
-rw-r--r-- 1 root root   612 Apr 13 02:17 index.nginx-debian.html
```

gitを使ってFlag.txtの編集履歴を確認、それらをつなげてフラグにします。

```
# apt install git
# git log --all -p Flag.txt
ommit 1b5bfaf9a29aff8173115b388e097765d9563252 (temporary)
Author: wanictf21spring <wanictf21spring@gmail.com>
Date:   Tue Apr 13 13:38:54 2021 +0900

    edit Flag.txt

diff --git a/html/Flag.txt b/html/Flag.txt
index 60ca0b1..f99f791 100644
--- a/html/Flag.txt
+++ b/html/Flag.txt
@@ -1 +1 @@
-FLAG{y0u_
+4r3_p3rf3c7_g1t

commit 6cc0b29f5ce571d1a1e36b43d91681dbae7c22aa
Author: wanictf21spring <wanictf21spring@gmail.com>
Date:   Tue Apr 13 10:17:23 2021 +0900

    edit Flag.txt

diff --git a/html/Flag.txt b/html/Flag.txt
index ef189e0..60ca0b1 100644
--- a/html/Flag.txt
+++ b/html/Flag.txt
@@ -1 +1 @@
-_m45t3r}
+FLAG{y0u_

commit b41601462b20845f9e0680fa77ebccd2cf42fe7c
Author: wanictf21spring <wanictf21spring@gmail.com>
Date:   Tue Apr 13 10:16:00 2021 +0900

    Flag.txt

diff --git a/html/Flag.txt b/html/Flag.txt
new file mode 100644
index 0000000..ef189e0
--- /dev/null
+++ b/html/Flag.txt
@@ -0,0 +1 @@
+_m45t3r}
```
