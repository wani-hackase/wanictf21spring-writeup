fp = open("./FLAG", "r")

flag = fp.read()

for i in range(len(flag)):
    val = flag[i]
    #    print(val)
    for j in range(8):
        #        print(ord(val))
        b = (ord(val) >> (7 - j)) & 0x01
        print(b)
