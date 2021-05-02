flag = "FLAG{S0rry_Hav3_you_b3en_wai7ing_lon6?_No_I_ju5t_g0t_her3}\0"

res = [0] * len(flag)

for i in range(len(flag)):
    res[i] = ord(flag[i]) ^ 0x22

print(len(flag))
print(res)
