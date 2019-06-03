# A. Reachable Numbers

n = int(input())
a = []
while n not in a:
    a.append(n)
    n+=1
    while n%10 is 0:
        n //= 10
print(len(a))