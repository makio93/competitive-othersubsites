# 学習1回目,解説AC

s = input()
t = ""

vows = "aiueo"
for c in s:
    if c.islower() and not c in vows:
        t = t + "_"
    else:
        t = t + c

print(t)
