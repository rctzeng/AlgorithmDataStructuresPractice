# UVa 10537 Toll! Revisited
## 題目大意
經過每個Town 和Village 時要過路費，Town 的過路費是每20 個item 收費一個item, 而Village 只收1個，求：從某處出發到一目的地要有n 個item的話，在出發點最少要帶幾個item ?
## Solve (Djikstra + math)
由終點往前推起點要帶的item 個數
數學推導:
已知Y 要往前推X 根據題目說的Town 過路費，可以列出下列式子：
X - floor(X/20) - c = Y, c = (X%20)==0?0:1
若 X/20 整除:
	let X=20k, 19k=Y => X=20(floor(Y/19))
若 X/20 不整除:
	let X=20k+r, r=1,...19
	20k+r - floor((20k+r)/20) - 1 = Y
 => 20k+r - k - floor(r/20) - 1 = Y
 => 19k + r-1 = Y (即 Y 除以19 的除法運算)
 => k = floor(Y/19), r-1 = Y%19
 => X = 20k+r = 20(floor(Y/19)) + Y%19+1

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<limits.h>

#define INF LONG_MAX
#define MAX 53

typedef struct node {
    char ch;
    int odr;
}node;

node O[MAX];
int G[MAX][MAX];
int P[MAX];
int V[MAX];
long long int D[MAX];
int num;

void read (int n);
void Djikstra (int s, int ini);
int cmp (const void *a, const void *b);
long long int findNum (long long int N);

int main() {
    int n;
    int test=0;
    while (~scanf("%d", &n) && n != -1) {

        if (n > 0) {
            read (n);

            char a, b;
            long long int item;
            scanf("%lld %c %c", &item, &a, &b);

            qsort (O, num, sizeof(node), cmp);
            // find start / end point
            int s, e;
            for (int i=0; i<num; i++) {
                if (a == O[i].ch) s = i;
                if (b == O[i].ch) e = i;
            }

            Djikstra (e, item);

            printf("Case %d:\n", ++test);
            printf("%lld\n", D[s]);
            printf("%c", O[s].ch);
            int tt = P[s];
            while (tt != -1) {
                printf("-%c", O[tt].ch);
                tt = P[tt];
            }
            puts("");
        } else {
            char a, b;
            long long int item;
            scanf("%lld %c %c", &item, &a, &b);

            printf("Case %d:\n", ++test);
            printf("%lld\n", item);
            printf("%c", a);
            puts("");
        }
    }

    return 0;
}

void read(int n) {
    char a, b;
    int f1, f2;
    memset (G, 0, sizeof(G));
    num = 0;
    while (n--) {
        scanf(" %c %c", &a, &b);
        // relabel
        f1 = f2 = -1;
        for (int i=0; i<num; i++) {
            if (a == O[i].ch)
                f1 = i;
            else if (b == O[i].ch)
                f2 = i;
        }

        if (f1 == -1) {
            f1 = num;
            O[num].ch = a;
            O[num].odr = num;
            num++;
        }

        if (f2 == -1) {
            f2 = num;
            O[num].ch = b;
            O[num].odr = num;
            num++;
        }

        G[f1][f2] = G[f2][f1] = 1;
    }
}

void Djikstra (int s, int ini) {
    // initialize
    memset(V, -1, sizeof(V));
    memset(P, -1, sizeof(P));
    for (int i=0; i<num; i++)
        D[i] = INF;

    D[s] = ini;
    // Djikstra
    for (int i=0; i<num; i++) {
        int disLeast = -1;
        long long int dis = INF;
        for (int j=0; j<num; j++) {
            if (V[j] == -1 && D[j] < dis) {
                disLeast = j;
                dis = D[j];
                }
        }
        if (disLeast != -1) {
            V[disLeast] = 1;
            for (int j=0; j<num; j++) {
                if (G[O[disLeast].odr][O[j].odr] == 1) {
                    long long int tt;
                    if (isupper(O[disLeast].ch)) {
                        tt = findNum(D[disLeast]);
                    } else {
                        tt = D[disLeast] + 1;
                    }

                    if (tt < D[j]) {
                        D[j] = tt;
                        P[j] = disLeast;
                    }
                }
            }
        }
    }
}

int cmp (const void *a, const void *b) {
    node c = *(node *)a;
    node d = *(node *)b;

    return c.ch - d.ch;
}

long long int findNum (long long int N) {
    long long int k = N/19;
    int b = N%19;
    if (b)  return k*20 + b + 1;
    return 20*k;
}
```
