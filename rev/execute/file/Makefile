all:
	gcc --version > version.txt
	gcc -S main.c
	gcc -shared -o libprint.so print.c
	rm main.c
	rm print.c
