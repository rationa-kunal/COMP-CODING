
# project euler
# problem 97
# Large non-Mersenne prime

def truncate(n):
    return n%10000000000

def solve():
    ans = 2
    p = 7830457
    d = 1
    p -= 1
    while p is not 0:
        _p = p - d
        if _p < 0 or _p is 0:
            break
        ans *= ans
        ans = truncate(ans)
        # print(ans)
        p -= d
        d *= 2
    # print("rem p", p)
    while p is not 0:
        ans *= 2
        ans = truncate(ans)
        p-=1
    ans = ans*28433
    ans = truncate(ans)
    ans = truncate(ans+1)
    return ans

print(solve())