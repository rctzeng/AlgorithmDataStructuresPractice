#include <stdio.h>

#define MAX 10000001

int check (int m, int k);
int ans[15];

int main () {
    int k;
    for (k=1;k<=14;k++) {
        int m;
        for (m=0;m<MAX;m++) {
            if (check(m,k)) {
                ans[k] = m;
                break;
            }
        }
    }

    while (scanf("%d", &k) && k)
        printf("%d\n", ans[k]);

    return 0;
}

int check (int m, int k) {
    int cur = (m-1)%(2*k);
    for(int i=1;i<k;i++) {
        cur  = (cur+m-1)%(2*k-i);
        if(cur < k)
            return 0;
    }

    return 1;
}
