from pwn import *
from math import gcd, lcm
from functools import reduce


def extended_gcd(a, b):
    c0, c1 = a, b
    a0, a1 = 1, 0
    b0, b1 = 0, 1

    while c1 != 0:
        q, m = divmod(c0, c1)
        c0, c1 = c1, m
        a0, a1 = a1, a0 - q * a1
        b0, b1 = b1, b0 - q * b1
    return a0, b0, c0


def garner(A, M):
    assert len(A) == len(M)

    n = len(A)
    a1, m1 = A[0], M[0]
    for i in range(1, n):
        a2, m2 = A[i], M[i]
        g = gcd(m1, m2)
        if a1 % g != a2 % g:
            return 0, 0
        p, q, _ = extended_gcd(m1 // g, m2 // g)
        mod = lcm(m1, m2)
        a1 = (a1 * (m2 // g) * q + a2 * (m1 // g) * p) % mod
        m1 = mod

    return a1, m1

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293]

s = remote("localhost", 50005)

A = []
for p in primes:
    s.sendlineafter("Mod > ", str(p))
    A.append(int(s.recvline().decode()))

y = 1
for p in primes:
    y *= p
flag = garner(A, primes)[0]
print(bytes.fromhex(f"{flag:x}").decode())
