key = "wani_is_the_coolest_animals_in_the_world!"
flg = "FLAG{ana1yze_4nd_strin6s_and_execu7e_6in}"

l = [0] * len(key)

for i in range(len(key)):
    l[i] = ord(key[i]) ^ ord(flg[i])

print(l)
