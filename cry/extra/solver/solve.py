import gmpy2
from Crypto.Util.number import long_to_bytes

with open("../file/output.txt") as f:
    N = int(f.readline().split(" = ")[-1])
    M = int(f.readline().split(" = ")[-1])
    e = int(f.readline().split(" = ")[-1])
    c = int(f.readline().split(" = ")[-1])


def solve_quad_equation(a, b, c):
    d = gmpy2.isqrt(b ** 2 - 4 * a * c)
    return (d - b) // (2 * a), (-d - b) // (2 * a)


P, Q = solve_quad_equation(1, -M, 2 * N)

if P % 2 == 0:
    p, q = P // 2, Q
else:
    p, q = Q, P // 2

d = pow(e, -1, (p - 1) * (q - 1))
m = pow(c, d, N)
plaintext = long_to_bytes(m)
print(plaintext.decode().strip())
