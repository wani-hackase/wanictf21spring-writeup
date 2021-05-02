fp = open("./packet.csv", "r")

vals = fp.readlines()

count = 1
pre_val = 0
current = 0
sampling_rate = 31

val_bins = []

for i in range(len(vals)):
    pre_val = current
    current = int(vals[i])
    if current == pre_val:
        count = count + 1
    else:
        count = 1

    if count == sampling_rate:
        val_bins.append(pre_val)
        count = 1

pre_val = 0
current = 0
next_bins = []
for i in range(len(val_bins) // 2):
    b0 = val_bins[i * 2]
    b1 = val_bins[i * 2 + 1]
    if b0 == 1 and b1 == 0:
        next_bins.append(1)
    elif b0 == 0 and b1 == 1:
        next_bins.append(0)

val_bins = next_bins[3:]

c = 0
for i in range(len(val_bins)):
    val = int(val_bins[i])
    c = (c << 1) | val
    if i % 8 == 7:
        print(chr(c), end="")
        c = 0

print("")
