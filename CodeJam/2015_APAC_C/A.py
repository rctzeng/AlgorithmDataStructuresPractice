import sys


def main():
    f = open('A-large-practice.in')
    sys.stdin = f
    f1 = open('outA.txt', 'w+')
    sys.stdout = f1
    T = int(input())
    for t in range(T):
        P = int(input())
        S = [int(x) for x in raw_input().split(' ')]
        N = int(input())
        names = {}
        value = []
        for i in range(N):
            name = raw_input().split(' ')
            w = int(name[0])
            del name[0]
            for j in range(len(name)):
                x = S[j]*w
                if name[j] in names:
                    index = names[name[j]]
                    value[index].append(x)
                else:
                    index = len(value)
                    names.update({name[j]: index})
                    value.append([x])
        M = int(input())
        rst = []
        for k, v in names.iteritems():
            sorted(value[v], reverse=True)
            rst.append((k, sum(value[v][:M])))
        rst.sort(key=lambda x: (-x[1], x[0]))
        print "Case #%d:" % (t+1)
        prev, r, c = -1, 0, 1
        for i in range(len(rst)):
            if rst[i][1] != prev:
                r += c
                c = 1
            else:
                c += 1
            prev = rst[i][1]
            print "%d: %s" % (r, rst[i][0])

if __name__ == '__main__':
    main()
