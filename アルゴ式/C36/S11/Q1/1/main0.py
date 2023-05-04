# 学習1回目,自力AC

s = input()
t = ""

vowels = "aiueo"
for i in range(len(s)):
    if s[i].islower() and vowels.count(s[i]) == 0:
        t = t + "_"
    else:
        t = t + s[i]

print(t)
