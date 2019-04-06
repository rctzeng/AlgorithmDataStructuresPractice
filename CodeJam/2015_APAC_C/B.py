import sys

def main():
    fin = open('B-small-practice.in', 'r')
    sys.stdin = fin
    fout = open('outB.txt', 'w+')
    sys.stdout = fout
    T = int(input())
    for t in range(T):
        N = int(input())
        left, right, f = 0, 2001, False
        r = right
        PKL = []
        for n in range(N):
            PK = [int(x) for x in raw_input().split(' ')]
            l = (PK[1]*100+PK[0])/(PK[0]+1)
            if PK[0] != 0:
                r = (PK[1]*100)/PK[0]
            elif PK[1] != 0:
                f = True
            left = max(left, l)
            right = min(right, r)
            PKL.append(PK)
        i = left
        ok = 0
        while i <= right and not f:
            if i != 0:
                for x in PKL:
                    if x[1]*100/i != x[0]:
                        f = True
                        break
                ok += 1
            else:
                for x in PKL:
                    if x[1] != 0:
                        f = True
                        break
            i += 1
        if not f and ok == 1:
            print "Case #%d: %d" % (t+1, left)
        else:
            print "Case #%d: -1" % (t+1)


if __name__ == '__main__':
    main()
