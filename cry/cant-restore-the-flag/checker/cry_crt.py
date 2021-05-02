from functools import reduce
from math import gcd

from Crypto.Util.number import long_to_bytes
from pwn import *


def lcm(x, y):
    return (x * y) // gcd(x, y)


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


def check_cry_crt(host):
    port = 50000

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293]
    flag = b"FLAG{Ch1n3s3_r3m@1nd3r_7h30r3m__so_u5eful}"
    try:
        s = remote(host, port, timeout=3)

        A = []
        for p in primes:
            s.sendlineafter("Mod > ", str(p))
            A.append(int(s.recvline().decode()))

        recovered_flag = garner(A, primes)[0]
        recovered_flag = long_to_bytes(recovered_flag)

        s.close()

        if flag in recovered_flag:
            return 0

        return 1

    except Exception as e:
        print(e)
        return 2


if __name__ == "__main__":
    print(check_cry_crt("localhost"))
