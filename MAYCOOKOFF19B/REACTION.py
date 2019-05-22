
def solve(a, r, c):
	ans = True
	if a[0][0] >= 2:
		return False
	if a[r-1][0] >= 2:
		return False
	if a[0][c-1] >=2:
		return False
	if a[r-1][c-1] >= 2:
		return False

	for i in range(1, r-1):
		if a[i][0] >= 3:
			return False

	for i in range(1, r-1):
		if a[i][c-1] >= 3:
			return False

	for i in range(1, c-1):
		if a[0][i] >= 3:
			return False

	for i in range(1, c-1):
		if a[r-1][i] >= 3:
			return False

	for i in range(1, r-1):
		for j in range(1, c-1):
			if a[i][j] >= 4:
				return False

	return True



t = int(input())

for T in range(t):

	r, c = input().split()
	r, c = int(r), int(c)

	a = []

	for ri in range(r):
		a.append(list(map(int, input().split())))


	ans = solve(a, r, c)
	if ans:
		print("Stable")
	else:
		print("Unstable")