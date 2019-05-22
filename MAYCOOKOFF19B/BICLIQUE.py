
def check(a, b, k):
    i, j, d=0, 0, 0
    while i<len(a) and j<len(b):
        if a[i] is b[j]:
            i+=1
            j+=1
            d+=1
        elif a[i]>b[j]:
            j+=1
        else:
            i+=1
        if d>=k:
            return True
    return False

n, m, k = input().split()
n, m, k = int(n), int(m), int(k)

g = [[] for i in range(n)]

for i in range(m):
    u, v = input().split()
    u, v = int(u), int(v)
    u-=1
    v-=1
    g[u].append(v)
    g[v].append(u)

for i in range(n):
    g[i].sort()

for i in range(n):
    for j in range(i+1, n):
        d=0

        if check(g[i], g[j], k):
            print("YES")
            exit()
    
print("NO")