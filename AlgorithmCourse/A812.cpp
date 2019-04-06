#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN -100000000
#define MAX 1001

int pile[50][20], prev[50][20];
int p[50], Mp[50];
int num[51][MAX];

int main() {
    int n, c;
    c=0;
    while(scanf("%d",&n)!=EOF && n) {
        for(int i=0;i<n;i++) {
            scanf("%d", &p[i]);
            Mp[i] = MIN;
            for(int j=0;j<p[i];j++) {
                scanf("%d", &pile[i][j]);
                if(j)   prev[i][j] = prev[i][j-1] + 10 - pile[i][j];
                else    prev[i][j] = 10 - pile[i][j];
                if(prev[i][j] > Mp[i])  Mp[i] = prev[i][j];
            }
        }

        memset(num, 0, sizeof(num));
        num[0][0]=1;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(Mp[i] >= 0) {
                ans += Mp[i];
                for(int j=0;j<p[i];j++) {
                    if(Mp[i] == prev[i][j]) {
                        for(int k=0;k<MAX;k++)
                            if(num[i][k])
                                num[i+1][k+j+1]=1;
                    }
                }

                if(Mp[i]==0) {
                    for(int k=0;k<MAX;k++)
                        if(num[i][k])
                            num[i+1][k] = 1;
                }
            } else {
                for(int k=0;k<MAX;k++)
                    num[i+1][k] = num[i][k];
            }
        }

        if(c)   printf("\n");
        printf("Workyards %d\n", ++c);
        printf("Maximum profit is %d.\n", ans);
        printf("Number of pruls to buy:");
        int ic = 0;
        if(ans == 0)    printf(" 0");
        for(int i=1;i<MAX && ic < 10;i++) {
            if(num[n][i]) {
                printf(" %d", i);
                ic++;
            }
        }

        printf("\n");
    }
    return 0;
}
