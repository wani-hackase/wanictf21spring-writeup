build:
	./build/bin/clang -c flag.c -mllvm -sub -mllvm -fla -mllvm -bcf -fPIE
	gcc -c main.c
	gcc flag.o main.o -o timer

install:
	git clone -b llvm-4.0 https://github.com/obfuscator-llvm/obfuscator.git
	mkdir build
	cd build
	cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_INCLUDE_TESTS=OFF ../obfuscator/
	make -j7
