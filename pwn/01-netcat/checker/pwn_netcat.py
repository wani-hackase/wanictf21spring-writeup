import socket


def check_pwn_netcat(hostname):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(3)
        sock.connect((hostname, 9001))
        data = sock.recv(1024)
        print(data)
        data = sock.recv(1024)
        print(data)
        sock.send(b"cat flag.txt\n")
        data = sock.recv(1024)
        print(data)

        sock.close()

        if data == b"FLAG{this_is_the_same_netcat_problem_as_previous_one}\n":
            return 0
        return 1

    except Exception as e:
        print(e)
        return 2


if __name__ == "__main__":
    ret = check_pwn_netcat("localhost")
    if ret == 0:
        print("alive")
