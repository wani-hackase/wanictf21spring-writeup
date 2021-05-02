with open("../file/output.txt") as f:
    ciphertext = f.read()


def decrypt(ciphertext: str, a: int, b: int) -> str:
    plaintext = ""
    for x in ciphertext:
        if "A" <= x <= "Z":
            x = ord(x) - ord("A")
            x = (x - b) * pow(a, -1, 26) % 26
            x = chr(x + ord("A"))
        plaintext += x

    return plaintext


if __name__ == "__main__":
    flag = decrypt(ciphertext, a=5, b=8)
    print(flag)
