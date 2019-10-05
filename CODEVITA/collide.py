import math

def calc(n):
	if n<2:
		return 0
	return n*(n-1)//2

def count_f(l, f):  
    for item in l: 
        if (item in f): 
            f[item] += 1
        else: 
            f[item] = 1

def time(x, y, v):
	return (math.sqrt(x*x + y*y))//v

c = int(input())

t = []

for i in range(c):
	t.append(time(*list(map(int, input().split()))))

t.sort()

ans = 0
f = 1
for i in range(1, c):
	if t[i] == 0:
		continue
	if t[i] != t[i-1]:
		ans += calc(f)
		f = 1
	else:
		f += 1
ans += calc(f)

print(ans)