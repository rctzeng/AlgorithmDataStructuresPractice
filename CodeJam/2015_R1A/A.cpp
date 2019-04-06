#include <stdio.h>

#define MAX 10001
#define max(x,y) (x)>(y)?(x):(y)

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int N;
        int m[MAX];
        scanf("%d", &N);
        int m1 = 0;
        int md = 0;
        for(int i=0;i<N;i++) {
            scanf("%d", &m[i]);
            if(i && m[i]<m[i-1]) {
                int d = m[i-1]-m[i];
                m1 += d;
                md = max(d, md);
            }
        }
        int m2 = 0;
        for(int i=0;i<N-1;i++)
            m2 += (m[i]<md)?m[i]:md;
        printf("Case #%d: %d %d\n", t, m1, m2);
    }

    return 0;
}
