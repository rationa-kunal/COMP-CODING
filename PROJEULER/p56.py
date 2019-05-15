
# project euler
# problem 56
# Powerful digit sum

def digit_sum(i, j):
    n = i**j
    s = 0
    while n is not 0:
        s += n%10
        n//=10
    return s

msum = 0
for i in range(1, 100):
    for j in range(1, 100):
        msum = max(digit_sum(i, j), msum)

print(msum)