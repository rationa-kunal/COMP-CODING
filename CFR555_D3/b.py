# B. Long Number

n = int(input())
a = list(input())
f = input().split()

i=0
for i in range(n):
    if a[i] < f[int(a[i])-1]:
        a[i]=f[int(a[i])-1]
        break

for j in range(i+1, n):
    if a[j] > f[int(a[j])-1]:
        break
    a[j]=f[int(a[j])-1]

print(''.join(a))