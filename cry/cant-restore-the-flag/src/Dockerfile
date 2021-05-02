FROM python:3.9-alpine

RUN apk --no-cache add socat

RUN apk add gcc
RUN apk add musl-dev
RUN apk add gmp-dev

RUN pip install pycrypto

ADD server.py server.py
ADD flag.txt flag.txt

CMD socat -T 120 -dd -v >/dev/stdout TCP-L:50000,fork,reuseaddr EXEC:"python -u server.py"
