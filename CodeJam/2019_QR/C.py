T = int(input())
for t in range(1,T+1):
    S = input().split(' ')
    N, L = int(S[0]), int(S[1])
    C = [int(x) for x in input().split(' ')]
    # build prime table
    P = [1 for i in range(N+1)]
    Primes = []
    P[0] = P[1] = 0
    for i in range(2,N+1):
        if P[i]==1:
            Primes += [i]
            for x in range(i+i,N+1,i):
                P[x] = 0
    # divide each number to recover letter mapping
    E, M = [0 for p in Primes], {}
    for c in C:
        if c not in M:
            divs, tc = [], c
            for i,p in enumerate(Primes):
                if tc%p==0:
                    while tc%p==0:
                        tc/=p
                        divs+=[i]
                    E[i]=1
                if len(divs)==2 or tc==0: break
            M[c] = list(sorted(divs))
    # build alphabet mapping
    A, c = {}, 0
    for i in range(len(Primes)):
        if E[i]==1:
            A[i] = chr(ord('A')+c)
            c+=1
    #print({Primes[k]:v for k,v in A.items()})
    # decipher text
    R, i = [], 0
    while i < len(C):
        cur_divs = M[C[i]]
        if i==0:
            NotDivisible, break_idx = [], None
            for j in range(i+1,len(C)): # must break
                nxt = M[C[j]]
                if nxt[0]==cur_divs[0] and nxt[1]==cur_divs[1]:
                    NotDivisible += [nxt]
                else:
                    break_idx = j
                    break
            b_divs = M[C[break_idx]]
            revR = []
            for j in range(break_idx-1, i-1, -1):
                j_divs = M[C[j]]
                if revR==[]:
                    p1, p2, p3 = None, None, None
                    for d1 in b_divs:
                        for d2 in j_divs:
                            if d1==d2: p2=d1
                    p1, p3 = p2, p2
                    for d1 in b_divs:
                        if d1!=p2: p1=d1
                    for d2 in j_divs:
                        if d2!=p2: p3=d2
                    revR += [p1,p2,p3]
                else:
                    cur = revR[-1]
                    for d in j_divs:
                        if d!=revR[-1]: cur=d
                    revR += [cur]
            R += revR[::-1]
            i = break_idx+1
        else:
            cur = R[-1]
            for d in cur_divs:
                if d!=R[-1]:cur=d
            R += [cur]
            i += 1
    ans = ''.join([A[r] for r in R])
    print('Case #{}: {}'.format(t, ans))
