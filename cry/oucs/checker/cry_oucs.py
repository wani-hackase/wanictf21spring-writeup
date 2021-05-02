from Crypto.Util.number import long_to_bytes
from pwn import remote


def check_cry_oucs(host):
    port = 50010
    flag = b"FLAG{OU_d0es_n0t_repre53nt_Osaka_University_but_Okamoto-Uchiyama}"
    try:
        s = remote(host, port, timeout=3)

        # Get the public key
        s.sendlineafter("> ", "4")
        n = int(s.recvline().decode().split(" = ")[-1], 0)

        # Get the encrypted flag [Enc(flag)]
        s.sendlineafter("> ", "1")
        ciphertext = int(s.recvline().decode().split(" = ")[-1], 0)

        # Get [Enc(1)]
        s.sendlineafter("> ", "2")
        s.sendlineafter("> ", "1")
        c = int(s.recvline().decode().split(" = ")[-1], 0)

        ciphertext = (c * ciphertext) % n

        # Decrypt
        s.sendlineafter("> ", "3")
        s.sendlineafter("> ", str(ciphertext))

        plaintext = int(s.recvline().decode().split(" = ")[-1], 0)
        plaintext = long_to_bytes(plaintext - 1)

        # Exit
        s.sendlineafter("> ", "5")

        if flag in plaintext:
            return 0

        return 1

    except Exception as e:
        print(e)
        return 2


if __name__ == "__main__":
    print(check_cry_oucs("localhost"))
