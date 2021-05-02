FROM ubuntu:18.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get -y update --fix-missing && apt-get -y upgrade
RUN apt-get -y install xinetd
RUN groupadd -r pwn && useradd -r -g pwn pwn

ADD ./src/pwn.xinetd /etc/xinetd.d/pwn
ADD ./src/init.sh    /etc/init.sh
ADD ./src/redir.sh   /home/pwn/redir.sh
RUN chmod 550        /home/pwn/redir.sh
RUN chmod 700        /etc/init.sh
RUN chmod 1733 /tmp /var/tmp /dev/shm

ADD ./src/FLAG        /home/pwn/flag.txt
ADD ./src/chall /home/pwn/chall
RUN chmod 440 /home/pwn/flag.txt
RUN chmod 550 /home/pwn/chall

RUN chown -R root:pwn /home/pwn

RUN ls /home/pwn -lh

RUN service xinetd restart
