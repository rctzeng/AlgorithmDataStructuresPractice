"""
N in [1, 10^100]
Big Number Problems
"""
T = int(input())
for t in range(1,T+1):
    N = input()
    # split to 2, 2
    A, B = [], []
    for i in range(len(N)-1, -1, -1):
        d = N[i]
        if d=='4':
            A += ['2']
            B += ['2']
        else:
            A += [N[i]]
            B += ['0']
    A = ''.join(A[::-1])
    # remove leading 0 in # B
    not0, B = 0, B[::-1]
    while B[not0]=='0': not0 += 1
    B = ''.join(B[not0:])
    print('Case #{}: {} {}'.format(t, A, B))
