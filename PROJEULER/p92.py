
# project euler
# problem 92
# Square digit chains

mem = [0 for i in range(1000)]
sq = [i**2 for i in range(10)]
solution = [None for i in range(1000)]
lim = 1000

def sq_sum(n):
    sum = 0
    while n is not 0:
        sum += (sq[n%10])
        n//=10

    return sum

def check(n):
    global solution
    global mem
    global lim
    if n>=lim:
        n = sq_sum(n)

    if n is 89:
        return True
    elif n is 1:
        return False

    if solution[n] is None:
        solution[n] = check(n)
        return solution[n]
    else:
        return solution[n]

# def check(n):
#     global lim
#     l = [n]
#     succ = False
    
#     if n >= lim:
#         n = sq_sum(n)
#         l.append(n)

#     while n is not 89 and n is not 1:
        
#         if solution[n] is not None:
#             succ = solution[n]
#             break
#         if mem[n] is 0:
#             mem[n] = sq_sum(n)
#         n = mem[n]

#         l.append(n)
#     l.append(n)

#     if n==89:
#         succ = True

#     for i in l:
#         if i < lim:
#             solution[i] = succ

#     return succ

ans = 0
for i in range(1, 1000000):
    if check(i):
        ans += 1
    # print(i)

print(ans)