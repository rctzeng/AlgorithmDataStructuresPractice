import math


def solve(S):
    MOD = 1000000007
    occur = transform(S)
    l = len(occur)/4
    pre = calc_pre(occur)
    ans = 0
    for a in range(l):
        for b in range(a, l):
            for c in range(b, l):
                xa = pre[(a+1)*4] # 0~a
                xb = pre[(b+1)*4+1] - pre[a*4+1] # a~b
                xc = pre[(c+1)*4+2] - pre[b*4+2] # b~c
                xd = pre[l*4+3] - pre[c*4+3] # c~l
                mac, mbd = min(xa, xc), min(xb, xd)
                sac, sbd = 0, 0
                for i in range(1, mac+1):
                    sac += combination(xa, i)*combination(xc, i)
                for i in range(1, mbd+1):
                    sbd += combination(xb, i)*combination(xd, i)
                ans = (ans + (sac % MOD) * (sbd % MOD)) % MOD
    return ans


def combination(n, r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)


def calc_pre(occur):
    pre = [0, 0, 0, 0]
    l = len(occur)
    for i in range(l):
        pre.append(occur[i]+pre[i])
    return pre


def transform(S):
    occur = []
    l = len(S)
    i, now, count = 0, 0, 0
    while i < l:
        if S[i] == chr(ord('a')+now):
            count += 1
            i += 1
        else:
            occur.append(count)
            count = 0
            now = (now+1) % 4
    while now != 0 or count != 0:
        occur.append(count)
        count = 0
        now = (now+1) % 4
    return occur


def main():
    T = int(input())
    for i in range(T):
        S = raw_input()
        ans = solve(S)
        print "Case #%d: %d" % (i+1, ans)


if __name__ == '__main__':
    main()
