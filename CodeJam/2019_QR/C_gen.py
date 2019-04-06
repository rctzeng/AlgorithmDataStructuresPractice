A = {2: 'A', 89: 'B', 109: 'C', 211: 'D', 239: 'E', 353: 'F', 479: 'G', 601: 'H', 701: 'I', 827: 'J', 883: 'K', 1021: 'L', 1051: 'M', 1087: 'N', 1277: 'O', 1381: 'P', 1531: 'Q', 1571: 'R', 1669: 'S', 1861: 'T', 1973: 'U', 1997: 'V', 2137: 'W', 2213: 'X', 2281: 'Y', 2411: 'Z'}
R = {v:k for k,v in A.items()}
C = "ZSZZZZZZUBDERMATOGLYPHICFJKNQVWXZ"
D = [R[c] for c in C]
F = [D[i-1]*D[i] for i in range(1,len(D))]
TXT = '1\n'
TXT += '10000 {}\n'.format(len(F))
TXT += '{}'.format(' '.join([str(x) for x in F]))

with open('C1.in', 'w+') as f:
    f.write(TXT)
