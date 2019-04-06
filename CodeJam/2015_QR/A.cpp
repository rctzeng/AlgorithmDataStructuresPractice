#include <stdio.h>

#define MAX 1000

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        int Smax, t, now, add, ans;
        scanf("%d", &Smax);
        now = add = ans = 0;
        getchar();
        for(int j=0;j<=Smax;j++) {
            t = getchar();
            t -= '0';
            if(t>0) {
                if(now < j) add = j-now;
                else    add = 0;
                ans += add;
                now += t + add;
            }
        }

        printf("Case #%d: %d\n", i, ans);
    }

    return 0;
}
