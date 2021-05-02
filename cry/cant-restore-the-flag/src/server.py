from Crypto.Util.number import bytes_to_long

with open("flag.txt", "rb") as f:
    flag = f.read()
flag = bytes_to_long(flag)

assert flag <= 10 ** 103

upper_bound = 300
while True:
    try:
        mod = int(input("Mod > "))
        if mod > upper_bound:
            print("Don't cheat 🤪")
            continue

        result = flag % mod
        print(result)
    except Exception:
        print("Bye 👋")
        break
