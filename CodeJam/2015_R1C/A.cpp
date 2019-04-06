#include <stdio.h>

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)

#define MAX_R 1
#define MAX_C 11

int dp[MAX_C][MAX_C];

int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("outA.txt", "w+", stdout);

    dp[1][1] = 1;
    for(int i=2;i<MAX_C;i++) {
        for(int w=1;w<=i;w++) {
            // initialize
            dp[i][w] = i;
            for(int j=0;j<i;j++) {
                // hit
                int hn = w+1;
                // not hit
                int nleft=j;
                int nright=(i-j-1);
                int pleft = nleft>=w?(dp[nleft][w]+1):0;
                int pright = nright>=w?(dp[nright][w]+1):0;
                int nhn = pleft+pright;
                if(pleft>0 && pright>0) nhn--;
                if(nhn && hn>=w) dp[i][w] = min(dp[i][w], max(hn,nhn));
            }
        }
    }

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int R, C, W;
        scanf("%d%d%d", &R,&C,&W);
        printf("Case #%d: %d\n", t, dp[C][W]);
    }

    return 0;
}
