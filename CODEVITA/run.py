n = int(input())
t = int(input())

p = []
for i in range(n):
	a = list(map(int, input().split()))
	d = a[t]
	_a = [a[0]*d]
	for i in range(1, t):
		_a.append(d*a[i]+_a[-1])
	p.append(_a)

winner = 0
winner_pt = 0
pts = [0 for i in range(n)]

# print(p)
for i in range(1, t, 2):
	MAXD = 0
	MAXW = 0 
	for j in range(n):
		# print(p[j][i])
		if MAXD < p[j][i]:
			MAXW = j
			MAXD = p[j][i]
	pts[MAXW] += 1
	if winner_pt < pts[MAXW]:
		winner_pt = pts[MAXW]
		winner = MAXW
	# print(winner, winner_pt, "\n")

print(winner+1)