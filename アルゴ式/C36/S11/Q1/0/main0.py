# 自力AC

S = input()

T = ""
ex = { 'a', 'i', 'u', 'e', 'o' }
for i in range(len(S)):
    if S[i].islower() and not S[i] in ex:
        T += '_'
    else:
        T += S[i]

print(T)
