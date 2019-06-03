# C1. Increasing Subsequence (easy version)

l = 'L'
r = 'R'

n = int(input())
a = list(map(int, input().split()))

i=0
j=n-1

ln = 0
curr = -1
st = []
while i<=j:
    if a[i]<a[j]:
        if curr < a[i]:
            st.append(l)
            curr = a[i]
            i += 1
            # ln += 1
        elif curr <= a[j]:
            st.append(r)
            curr = a[j]
            j -= 1
        else:
            break
    else:
        if curr < a[j]:
            st.append(r)
            curr = a[j]
            j -= 1
            # ln += 1
        elif curr <= a[i]:
            st.append(l)
            curr = a[i]
            i += 1
        else:
            break

print(len(st))
print(''.join(st))