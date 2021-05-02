fp = open("./binary.csv", "r")

vals = fp.readlines()

c = 0
for i in range(len(vals)):
    val = int(vals[i])
    c = (c << 1) | val
    if i % 8 == 7:
        print(chr(c), end="")
        c = 0

print("")
