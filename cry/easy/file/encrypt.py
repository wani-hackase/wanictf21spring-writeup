with open("flag.txt") as f:
    flag = f.read().strip()


A = REDACTED
B = REDACTED

plaintext_space = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_{}"

assert all(x in plaintext_space for x in flag)


def encrypt(plaintext: str, a: int, b: int) -> str:
    ciphertext = ""
    for x in plaintext:
        if "A" <= x <= "Z":
            x = ord(x) - ord("A")
            x = (a * x + b) % 26
            x = chr(x + ord("A"))
        ciphertext += x

    return ciphertext


if __name__ == "__main__":
    ciphertext = encrypt(flag, a=A, b=B)
    print(ciphertext)
