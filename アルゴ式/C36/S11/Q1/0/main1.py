# 解説AC

S = input()

T = ""
for c in S:
    if c.islower() and not c in { 'a', 'e', 'i', 'o', 'u' }:
        T += '_'
    else:
        T += c

print(T)
