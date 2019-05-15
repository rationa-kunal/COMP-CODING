
# project euler
# problem 55
# Lychrel numbers

def rev(n):
    rev = 0
    while n is not 0:
        rev*=10
        rev+=n%10
        n//=10
    return rev

def is_palindrome(n):
    return n == rev(n)

def is_lych(n):
    counter = 50
    while counter is not 0:
        n = n + rev(n)
        if is_palindrome(n):
            return True
        counter -= 1

    return False


ans = 0
for i in range(1, 10001):
    if not is_lych(i):
        ans += 1

print(ans)
