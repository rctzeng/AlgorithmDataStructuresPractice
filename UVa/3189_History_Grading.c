#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)

int main(){
    int n,i,j,t;
    int ans[21], studt[21], dp[21][21];

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        ans[t]=i;
    }
    while(~scanf("%d",&t)){
        studt[t]=1;
        for(i=2;i<=n;i++){
            scanf("%d",&t);
            studt[t]=i;
        }

        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                if(ans[i]==studt[j])    dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        printf("%d\n",dp[n][n]);
    }

    return 0;
}
