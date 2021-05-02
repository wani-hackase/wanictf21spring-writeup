# WA solution
from pwn import *

class rule30:
    def __init__(self, bits: int = 15):
        self.bits = bits

    def apply(self, state: int):
        if state in set([0b000, 0b101, 0b110, 0b111]):
            return 0
        elif state in set([0b001, 0b010, 0b011, 0b100]):
            return 1
        else:
            print("state is invalid")
            sys.exit()

    def calc(self, state: int):
        ret = 0
        for i in range(self.bits):
            tmp = 0
            tmp |= (state & (1 << ((i + 1) % self.bits))) > 0
            tmp <<= 1
            tmp |= (state & (1 << i)) > 0
            tmp <<= 1
            tmp |= (state & (1 << ((i - 1 + self.bits) % self.bits))) > 0
            ret |= self.apply(tmp) << i
        return ret

    def doubling(self, init: int, gen: int):
        now = init
        state = [list(range(1 << self.bits)), [0] * (1 << self.bits)]
        flag = True
        exp = 0
        for i in range(1 << (self.bits)):
            state[1][i] = self.calc(i)
        if gen & (1 << exp) > 0:
            now = state[1][now]
        exp += 1
        while gen >= (1 << exp):
            flag = not flag
            for i in range(1 << self.bits):
                state[flag][i] = state[not flag][state[not flag][i]]
            if gen & (1 << exp) > 0:
                now = state[flag][now]
            exp += 1
        return now
    def patternsearch(self, init:int, gen:int):
        generations = []
        loopstart = 0
        loopsize = 0
        generations.append(init)
        tmp = init
        for _ in range(gen):
            tmp = self.calc(tmp)
            if tmp in generations:
                loopstart = generations.index(tmp)
                loopsize = len(generations) - loopstart
                break
            generations.append(tmp)
        if len(generations) >= gen + 1:
            return generations[gen]
        else:
            return generations[loopstart + (gen-loopstart)%loopsize]
    def solve(self, init:int, gen:int):
        return self.patternsearch(init,gen)
    def bruteforce(self, init:int, gen:int):
        generations = []
        loopstart = 0
        loopsize = 0
        generations.append(init)
        tmp = init
        for _ in range(gen):
            tmp = self.calc(tmp)
            if tmp in generations:
                loopstart = generations.index(tmp)
                loopsize = len(generations) - loopstart
                break
            generations.append(tmp)
        if len(generations) >= gen + 1:
            return generations[gen]
        else:
            return generations[loopstart + 2]

solver = rule30(bits=15)
for i in range(100):
    print('CHALLENGE '+str(i))
    sock = remote("localhost", 50010)
    # sock = remote("localhost", 50010)
    sock.recv(1024)
    sock.sendline()
    print("Question 1")
    sock.recvuntil("=")
    init = sock.recvline().strip()
    sock.recvuntil("=")
    n = sock.recvline().strip()
    print(init, n)
    sock.sendline(format(solver.solve(int(init, 2), int(n)), "015b"))
    print("Question 2")
    sock.recvuntil("=")
    init = sock.recvline().strip()
    sock.recvuntil("=")
    n = sock.recvline().strip()
    print(init, n)
    sock.sendline(format(solver.solve(int(init, 2), int(n)), "015b"))
    print("Question 3")
    sock.recvuntil("=")
    init = sock.recvline().strip()
    sock.recvuntil("=")
    n = sock.recvline().strip()
    print(init, n)
    sock.sendline(format(solver.bruteforce(int(init, 2), int(n)), "015b"))
    if not (b'disappointed' in sock.recvline()):
        print('ok!!!')
        break
