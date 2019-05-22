import sys

t = int(input())

for T in range(t):
	n = int(input())

	a = list(map(int, input().split()))


	d1 = a[1]-a[0]
	d2 = a[2]-a[1]
	d3 = a[3]-a[2]

	fcond = d1 is d2
	scond = d2 is d3

	fr = 0
	d = 0

	if fcond:
		d = d1
		fr = a[0]
	elif scond:
		d = d3
		fr = a[1]-d
	else:
		d = (a[3]-a[0])//3
		fr = a[0]

	for i in range(n):
		sys.stdout.write(str(fr))
		sys.stdout.write(' ') 
		fr += d

	print()
	
