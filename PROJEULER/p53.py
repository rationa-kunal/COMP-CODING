
# project euler
# problem 53
# Combinatoric selections

n = 100
N = 1000000

fact = []

# calculate factorials
fact.append(1)
for i in range(1, 101):
    fact.append(fact[i-1]*i)


def ncr(n, r):

    max, min = 0, 0
    if(r > (n-r)):
        max = r
        min = n-r
    else:
        max = n-r
        min = r

    upper = 1
    for i in range(max+1, n+1):
        upper*=i
    
    down = fact[min]

    return upper // down


def main():
    global N
    count = 0

    for n in range(1, 101):
        for r in range(0, n+1):
            if(ncr(n, r) >= N):
                count +=1

    print(count)

main()