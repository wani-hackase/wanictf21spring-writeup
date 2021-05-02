fp = open("./FLAG", "r")

flag = fp.read()

sampling_rate = 31


def send_null(sec):
    for i in range(sec * sampling_rate):
        print("0")


def send_preamble():
    s = "\xAA\xAA\xAA\xAA"

    for i in range(len(s)):
        val = s[i]
        for j in range(8):
            b = (ord(val) >> (7 - j)) & 0x01
            for _ in range(sampling_rate):
                print(b)


def send_startcode():
    s = "\xE5"
    for i in range(len(s)):
        val = s[i]
        for j in range(8):
            b = (ord(val) >> (7 - j)) & 0x01
            for _ in range(sampling_rate):
                print(b)


def send_flag(flag):
    for i in range(len(flag)):
        val = flag[i]
        for j in range(8):
            b = (ord(val) >> (7 - j)) & 0x01
            for _ in range(sampling_rate):
                print(b)


def send(flag):
    send_null(50)
    send_preamble()
    send_startcode()
    send_flag(flag)


for _ in range(10):
    send(flag)
