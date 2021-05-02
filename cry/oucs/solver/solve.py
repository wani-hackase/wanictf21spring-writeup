from Crypto.Util.number import long_to_bytes
from pwn import remote

s = remote("localhost", 50010)

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
flag = long_to_bytes(plaintext - 1)

print(flag)
