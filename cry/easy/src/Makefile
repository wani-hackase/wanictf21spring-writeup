../file/output.txt: encrypt.py flag.txt
	python -B encrypt.py	> ../file/output.txt

test: ../solver/solve.py ../file/encrypt.py ../file/output.txt flag.txt
ifeq ($(shell python -B ../solver/solve.py), $(shell cat flag.txt))
	@printf "\033[32m[+] Test passed\033[0m"
else
	@printf "\033[31m[x] Test failed\033[0m"
endif

.PHONY: test
