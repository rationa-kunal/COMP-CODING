from pprint import pprint

def create_steps(x1, y1, st, a, s, _steps):
	n = len(a)
	m = len(a[0])

	d = a[x1][y1]
	if d is -1:
		return 
	a[x1][y1] = -1 
	for dx2 in range(0, d+1):
		dy2 = d - dx2

		if x1+dx2 < n and y1+dy2 < m:
			if(s[x1+dx2][y1+dy2]) is -1:
				s[x1+dx2][y1+dy2] = st
				_steps.append([x1+dx2, y1+dy2])

		if x1-dx2 > -1 and y1+dy2 < m:
			if(s[x1-dx2][y1+dy2]) is -1:
				s[x1-dx2][y1+dy2] = st
				_steps.append([x1-dx2, y1+dy2])

		if x1+dx2 < n and y1-dy2 > -1:
			if(s[x1+dx2][y1-dy2]) is -1:
				s[x1+dx2][y1-dy2] = st
				_steps.append([x1+dx2, y1-dy2])

		if x1-dx2 > -1 and y1-dy2 > -1:
			if(s[x1-dx2][y1-dy2]) is -1:
				s[x1-dx2][y1-dy2] = st
				_steps.append([x1-dx2, y1-dy2])


def solve(x, y, a, s):
	n = len(a)
	m = len(a[0])
	steps = [[x, y]]
	_steps = []
	st = 0
	s[x][y] = 0
	while len(steps) is not 0:
		st += 1
		_steps = []
		for pt in steps:
			create_steps(pt[0], pt[1], st, a, s, _steps)
		steps = _steps
		# pprint(a)
		# print('s {')
		# for ss in s:
		# 	print(ss)
		# print('}')
		# pprint(steps)
		# # pprint(_steps)
		# print('\n')

t = int(input())

for T in range(t):

	n, m = input().split()
	n, m = int(n), int(m)

	a = []
	s = []
	for i in range(n):
		a.append(list(map(int, input().split())))
		s.append([-1 for ii in range(m)])

	x, y = input().split()
	x, y = int(x), int(y)
	x-=1
	y-=1
	solve(x, y, a, s)

	q = int(input())

	for Q in range(q):
		x, y = input().split()
		x, y = int(x), int(y)
		x-=1
		y-=1
		print(s[x][y])

