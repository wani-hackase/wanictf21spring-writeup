#!/bin/bash

cd $(dirname $0)

gcc --version > version.txt

gcc -shared -o libprint.so print.c

gcc -S main.c
as -o main.o main.s
gcc -o main main.o -I./ -L./ -lprint

# gcc -I./ -L./ main.c -o main -lprint

export LD_LIBRARY_PATH=$(dirname $0) ; ./main

rm -rf execute/
mkdir execute/

cp libprint.so execute/
cp main.s execute/
cp version.txt execute/
cp Makefile execute/

rm version.txt
rm libprint.so
rm main.s
rm main.o
rm main

rm -rf ../file/execute.zip
7z a execute.zip execute/
cp execute.zip ../file
rm execute.zip
