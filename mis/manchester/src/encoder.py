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


def send_bits(bits):
    for val in bits:
        for _ in range(sampling_rate):
            print(val)


def make_bits(flag):
    ret = []
    for i in range(len(flag)):
        val = flag[i]
        for j in range(8):
            b = (ord(val) >> (7 - j)) & 0x01
            ret.append(b)
    return ret


def manchester(bits):
    ret = []
    for val in bits:
        if val == 0:
            ret.append(0)
            ret.append(1)
            print("01")
        else:
            ret.append(1)
            ret.append(0)
            print("10")
    return ret


def send_flag(flag):
    ret = make_bits(flag)
    ret = manchester(ret)
    send_bits(ret)


def send(flag):
    send_null(50)
    send_preamble()
    send_startcode()
    send_flag(flag)


for _ in range(5):
    send(flag)
