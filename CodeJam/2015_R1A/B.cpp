#include <stdio.h>

#define MAX 1001

int toSort[MAX];
int B, N;
int b[MAX];

long long int compute(long long int x);

int main() {
    int T = 0;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        scanf("%d%d", &B, &N);
        for(int i=0;i<B;i++)
            scanf("%d", &b[i]);

        long long int l=0, r=1e15, m;
        while(l<r) {
            m = (l+r)>>1;
            long long int sum = compute(m);
            if(sum>=N) r=m;
            else    l=m+1;
        }

        int sum = 0, tn = 0;
        for(int i=0;i<B;i++) {
            sum += l/b[i]+1;
            if(!(l%b[i]))
                toSort[tn++] = i+1;
        }

        printf("Case #%d: %d\n", t, toSort[tn-(sum-N)-1]);
    }

    return 0;
}

long long int compute(long long int x) {
    long long int num = 0;
    for(int i=0;i<B;i++)
        num += x/b[i]+1;
    return num;
}
