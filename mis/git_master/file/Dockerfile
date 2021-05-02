FROM ubuntu:20.04

LABEL maintainer="wanictf21spring@gmail.com"

RUN apt update \
 && apt install -y nginx

EXPOSE 80

COPY . /var/www

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
