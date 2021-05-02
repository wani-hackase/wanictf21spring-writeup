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


def check_pwn_netcat_v02(hostname):
    try:
        io = pwn.remote(hostname, 9002, timeout=5)
    except:
        return 2

    try:
        ret = read_until(io, b"command\n")
        print(ret)
        io.send(b"cat flag.txt\n")
        ret = read_until(io, b"}")
        print(ret)
        flag = get_flag_msg(ret)

        if flag == b"FLAG{this_is_the_same_netcat_problem_as_previous_one}":
            return 0
        return 1

    except Exception as e:
        print(e)
        return 1

    finally:
        io.close()


if __name__ == "__main__":
    ret = check_pwn_netcat_v02("netcat.pwn.wanictf.org")
    if ret == 0:
        print("alive")
