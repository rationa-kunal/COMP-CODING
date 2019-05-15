#
# project euler
# problem 36
# Double-base palindromes
#

def rev(n):
    r = 0
    while n is not 0:
        r *= 10
        r += (n%10)
        n //= 10
    return r

def is_palindrome(n):
    return rev(n) == n

def bin(n):
    b = 1
    while n is not 0:
        b *= 10
        b += (n%2)
        n //= 2
    b = rev(b)
    b//=10
    return b

def main():
    sum = 0
    for i in range(1, 1000000):
        if is_palindrome(i):
            if is_palindrome(bin(i)):
                sum += i
    
    print(sum)

main()