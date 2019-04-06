#include <stdio.h>

#define MAX 1001
#define max(x,y) (x)>(y)?(x):(y)

int P[MAX];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int n, best, M;
        scanf("%d", &n);
        for(int i=1;i<MAX;i++) P[i] = 0;
        M = 0;
        for(int i=0;i<n;i++) {
            scanf("%d", &P[i]);
            M = max(M, P[i]);
        }
        best = M;
        for(int i=2;i<=M;i++) {
            int t = 0;
            for(int j=0;j<n;j++)    t += (P[j]+i-1)/i-1;
            if(t+i < best)  best = t+i;
        }

        printf("Case #%d: %d\n", t, best);
    }

    return 0;
}
