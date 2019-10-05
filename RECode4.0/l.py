s = list(input())

first_c = 0
for i in range(len(s)):
    if s[i] is 'c':
        first_c = i
        break

first_p = 0
for i in range(len(s))