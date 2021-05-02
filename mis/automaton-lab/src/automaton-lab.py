import sys
from concurrent.futures import ThreadPoolExecutor
import random
from Crypto.Util.number import getPrime

import const
import automaton

cells = 15


def checkanswer(reference, answer):
    if len(answer) != cells:
        print(const.error)
        sys.exit()
    for c in answer:
        if not (c == "0" or c == "1"):
            print(const.error)
            sys.exit()
    answer = int(answer, 2)
    if reference != answer:
        print(const.lose)
        sys.exit()
    return

solver = automaton.rule30(bits=cells)
print(const.message1)
input()

# 1st Question
init = random.randint(1, 2**cells - 2)
gen = 7
reference = solver.solve(init, gen)
print(const.quiz1)
print("init = " + format(init, "0"+str(cells)+"b"))
print("gen = " + str(gen))
answer = input("> ")
checkanswer(reference, answer)

# 2nd Question
init = (1 << random.randint(0, cells-1)) | (1 << random.randint(0, cells-1))
gen = 997
reference = solver.solve(init, gen)
print(const.quiz2)
print("init = " + format(init, "0"+str(cells)+"b"))
print("gen = " + str(gen))
answer = input("> ")
checkanswer(reference, answer)

# 3rd Quiestion
init = 1
gen = getPrime(1024)
reference = solver.solve(init, gen)
print(const.quiz3)
print("init = " + format(init, "0"+str(cells)+"b"))
print("gen = " + str(gen))
answer = input("> ")
checkanswer(reference, answer)

# Congratz
print(const.message2)
print(const.flag)