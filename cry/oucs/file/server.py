import random

from Crypto.Util.number import bytes_to_long, getPrime, long_to_bytes

from const import description, flag, logo


class OkamotoUchiyamaCryptoSystem:
    def __init__(self, bits: int):
        p, q = getPrime(bits), getPrime(bits)
        n = p * p * q

        while g := random.randrange(2, n):
            if pow(g, p - 1, p * p) != 1:
                break
        h = pow(g, n, n)

        self.p = p
        self.n = n
        self.g = g
        self.h = h

    def encrypt(self, plaintext: bytes) -> bytes:
        plaintext = bytes_to_long(plaintext)
        n, g, h = self.n, self.g, self.h
        r = random.randrange(2, n)

        ciphertext = pow(g, plaintext, n) * pow(h, r, n) % n
        ciphertext = long_to_bytes(ciphertext)

        return ciphertext

    def decrypt(self, ciphertext: bytes) -> bytes:
        ciphertext = bytes_to_long(ciphertext)
        p, g = self.p, self.g

        a = (pow(ciphertext, p - 1, p ** 2) - 1) // p
        b = (pow(g, p - 1, p * p) - 1) // p
        b_ = pow(b, -1, p)
        plaintext = a * b_ % p
        plaintext = long_to_bytes(plaintext)

        return plaintext

    def get_publickey(self) -> tuple[int, int, int]:
        return self.n, self.g, self.h


if __name__ == "__main__":
    print(logo)
    cipher = OkamotoUchiyamaCryptoSystem(bits=1024)

    while True:
        print()
        print(description)
        while not (choice := input("> ")) in "12345":
            print("Invalid choice.")

        choice = int(choice)

        # 1. Encrypt the flag
        if choice == 1:
            ciphertext = cipher.encrypt(flag)
            ciphertext = bytes_to_long(ciphertext)
            print(f"{ciphertext = :#x}")

        # 2. Encrypt
        elif choice == 2:
            print("Enter your plaintext")
            plaintext = int(input("> "), 0)
            plaintext = long_to_bytes(plaintext)

            ciphertext = cipher.encrypt(plaintext)
            ciphertext = bytes_to_long(ciphertext)
            print(f"{ciphertext = :#x}")

        # 3. Decrypt
        elif choice == 3:
            print("Enter your ciphertext")
            ciphertext = int(input("> "), 0)
            ciphertext = long_to_bytes(ciphertext)

            # ... except for the flag
            plaintext = cipher.decrypt(ciphertext)
            if flag == plaintext:
                print("Decryption succeeded, but we won't tell you the result :P")
                continue
            plaintext = bytes_to_long(plaintext)
            print(f"{plaintext = :#x}")

        # 4. Show public key
        elif choice == 4:
            n, g, h = cipher.get_publickey()
            print(f"{n = :#x}")
            print(f"{g = :#x}")
            print(f"{h = :#x}")

        # 5. Exit
        else:
            print("Bye :)")
            break
