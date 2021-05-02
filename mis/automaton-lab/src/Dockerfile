FROM python:3.8-alpine

RUN apk --no-cache add socat

RUN apk add gcc
RUN apk add musl-dev
RUN apk add gmp-dev

RUN python -m pip install --upgrade pip
RUN pip install pycryptodome

ADD automaton-lab.py automaton-lab.py
ADD automaton.py automaton.py
ADD const.py const.py

CMD socat -T 120 -dd -v >/dev/stdout TCP-L:50010,fork,reuseaddr EXEC:"python -u automaton-lab.py"
