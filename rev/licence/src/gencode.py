import os
import random

"""
フラグ文字列のascii範囲 : 48 ~ 125

# xor

if (flag[1] ^ 150 == 130) {
  return 0;
}

# add

if (flag[1] + 50 == 130) {
  return 0;
}

# sub

if (flag[1] - 50 == 20) {
  return 0;
}
"""


def fail(i, stat):
    r = random.randint(0, len(flag) - 1)
    s = random.randint(1, 10)
    if stat == "xor":
        v = ord(flag[i]) ^ ord(flag[r]) + s
        code = "if ((flag[{}] ^ flag[{}]) == {}) \n".format(str(i), str(r), str(v))
    if stat == "add":
        v = ord(flag[i]) + ord(flag[r]) + s
        code = "if ((flag[{}] + flag[{}]) == {}) \n".format(str(i), str(r), str(v))
    if stat == "sub":
        v = ord(flag[i]) - ord(flag[r]) + s
        code = "if ((flag[{}] - flag[{}]) == {}) \n".format(str(i), str(r), str(v))
    code += "{\n"
    code += "  return 1;\n"
    code += "}\n"
    return code


def success(i, stat):
    if i == 0:
        r = random.randint(10, 100)
        if stat == "xor":
            v = ord(flag[i]) ^ r
            code = "if ((flag[{}] ^ {}) == {}) \n".format(str(i), str(r), str(v))
        if stat == "add":
            v = ord(flag[i]) + r
            code = "if ((flag[{}] + {}) == {}) \n".format(str(i), str(r), str(v))
        if stat == "sub":
            v = ord(flag[i]) - r
            code = "if ((flag[{}] - {}) == {}) \n".format(str(i), str(r), str(v))
        return code
    else:
        r = i - 1
        if stat == "xor":
            v = ord(flag[i]) ^ ord(flag[r])
            code = "if ((flag[{}] ^ flag[{}]) == {}) \n".format(str(i), str(r), str(v))
        if stat == "add":
            v = ord(flag[i]) + ord(flag[r])
            code = "if ((flag[{}] + flag[{}]) == {}) \n".format(str(i), str(r), str(v))
        if stat == "sub":
            v = ord(flag[i]) - ord(flag[r])
            code = "if ((flag[{}] - flag[{}]) == {}) \n".format(str(i), str(r), str(v))
        return code


def generate(d):
    l = ["xor", "add", "sub"]
    code = ""
    if d == len(flag):
        code += "return 0;"
    if d != len(flag):
        code += fail(d, random.choice(l))
        code += fail(d, random.choice(l))
        code += fail(d, random.choice(l))
        code += success(d, random.choice(l))
        code += "{\n"
        code += generate(d + 1)
        code += "}\n"
        code += fail(d, random.choice(l))
        code += fail(d, random.choice(l))
        code += fail(d, random.choice(l))
        code += "return 1;"
    return code


flag = "FLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}\n"
code = generate(0)
code += "return 1;"

with open("template.c", "r") as f:
    template = f.read()
with open("main.c", "w") as f:
    f.write(template.replace("????", code))

os.system("make")
