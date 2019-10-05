
def get_prefix(s, i):
    ss = ""
    for j in range(0, i+1):
        ss += s[i]
    return ss


s = input()

result = 0
occ = 0

for i in range(len(s)):
    ss = get_prefix(s, i)
    socc = s.count(ss)
    if socc >= occ:
        occ = socc
        result = ss
    else:
        break

print(occ)