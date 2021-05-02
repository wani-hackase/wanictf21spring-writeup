import socket
import sys


def check_mis_automaton(host):
    flag = b"FLAG{W3_4w4rd_y0u_d0c70r473_1n_Fu7ur3_S1gh7}"
    port = 50020

    class rule30:
        def __init__(self, bits: int = 10):
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

        def solve(self, init: int, gen: int):
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

    try:
        solver = rule30(bits=15)
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        def recvuntil(char):
            ret = b""
            while 1:
                tmp = s.recv(1)
                ret += tmp
                if tmp == char:
                    break
            return ret

        s.settimeout(30)
        s.connect((host, port))
        s.recv(1024)
        s.send(b"\n")
        for _ in range(3):
            if s.recv(1) == b"W":
                return 1
            recvuntil(b"=")
            init = int(recvuntil(b"\n").strip(), 2)
            recvuntil(b"=")
            gen = int(recvuntil(b"\n").strip())
            s.recv(64)
            answer = solver.solve(init, gen)
            s.send((format(answer, "015b") + "\n").encode())
        if b'disappointed' in recvuntil(b"\n"):
            return 1
        flagstr = recvuntil(b"\n")
        if flag in flagstr:
            return 0
        return 1
    except Exception as e:
        print(e)
        return 2
    finally:
        s.close()
