FROM php:7.2-apache

RUN apt-get update \
    && apt-get install -y libpq-dev \
    && docker-php-ext-install pdo_mysql pdo_pgsql

COPY php.ini /usr/local/etc/php

COPY ./html /var/www/html
