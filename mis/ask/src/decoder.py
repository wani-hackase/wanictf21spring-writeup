fp = open("./packet.csv", "r")

vals = fp.readlines()

count = 1
pre_val = 0
current = 0

val_bins = []

for i in range(len(vals)):
    pre_val = current
    current = int(vals[i])
    if current == pre_val:
        count = count + 1
    else:
        count = 1

    if count == 31:
        print(pre_val)
        val_bins.append(pre_val)
        count = 1

c = 0
for i in range(len(val_bins)):
    val = int(val_bins[i])
    c = (c << 1) | val
    if i % 8 == 7:
        print(chr(c), end="")
        c = 0

print("")
