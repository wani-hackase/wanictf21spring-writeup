from Crypto.Util.number import getPrime, bytes_to_long

with open("flag.txt", "rb") as f:
    flag = f.read()

p, q = getPrime(1024), getPrime(1024)
N = p * q
M = 2 * p + q
e = 0x10001


def encrypt(plaintext: bytes) -> int:
    plaintext = bytes_to_long(plaintext)
    c = pow(plaintext, e, N)

    return c


if __name__ == "__main__":
    c = encrypt(flag)

    print(f"{N = }")
    print(f"{M = }")
    print(f"{e = }")
    print(f"{c = }")
