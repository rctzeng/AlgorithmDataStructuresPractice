#include<stdio.h>

#define MAX 5000000000000000000
#define Max 91

long long int dp[Max];
int ans[Max];

int main(){
    int i,l,last;
    dp[0]=dp[1]=1;
    for(i=2;i<Max;i++)
        dp[i]=dp[i-1]+dp[i-2];

    long long int n,left;
    while(scanf("%lld",&n)!=EOF){
        l=0;
        left=n;last=Max+1;
        for(i=Max-1;i>=0;i--){
            if(last-i>1){
                if(dp[i]<left){
                    left-=dp[i];
                    ans[l++]=i;
                    last=i;
                }else if(dp[i]==left){
                    left=0;
                    ans[l++]=i;
                    last=i;
                    break;
                }
            }
        }
        printf("%lld\n",n);
        for(i=0;i<l;i++)
            printf("%d ",ans[i]);
        printf("\n");

        for(i=0;i<l;i++)
            printf("%lld ",dp[ans[i]]);
        printf("\n\n");
    }

    return 0;
}
