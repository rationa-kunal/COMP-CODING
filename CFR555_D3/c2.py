# c2. Increasing Subsequence (hard version)

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
        elif curr < a[j]:
            st.append(r)
            curr = a[j]
            j -= 1
        else:
            break
    elif a[j]<a[i]:
        if curr < a[j]:
            st.append(r)
            curr = a[j]
            j -= 1
            # ln += 1
        elif curr < a[i]:
            st.append(l)
            curr = a[i]
            i += 1
        else:
            break
    else:
        if curr > a[j]:
            break
        ll = 1
        i_ = i+1
        while i_<j and a[i_] > a[i_-1]:
            ll += 1
            i_ += 1
        lr = 1
        j_ = j-1
        while i<j_ and a[j_+1] < a[j_]:
            lr += 1
            j_ -= 1
        if ll>lr:
            for ii in range(ll):
                st.append(l)
        else:
            for ii in range(lr):
                st.append(r)
        break

print(len(st))
print(''.join(st))