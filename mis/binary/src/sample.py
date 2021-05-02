s = "WANI"
bits = []
for i in range(len(s)):
    val = s[i]
    for j in range(8):
        b = (ord(val) >> (7 - j)) & 0x01
        bits.append(b)

print(bits)

s = ""
c = 0
for i in range(len(bits)):
    val = int(bits[i])
    c = (c << 1) | val
    if i % 8 == 7:
        s = s + chr(c)
        c = 0

print(s)
