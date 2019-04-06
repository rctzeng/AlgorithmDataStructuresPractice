#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <map>

#define MAX 601

using namespace std;

int arr[MAX],dep[MAX],dp[MAX][MAX],par[MAX][MAX];

int main(){
    int t,n,i,j,k,pn,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<int,int> Re;
        for(i=0;i<n;i++){
            scanf("%d%d",&arr[i],&dep[i]);
            Re[arr[i]]=Re[dep[i]]=1;
        }
        pn=0;
        for(map<int,int>::iterator it = Re.begin();it!=Re.end();it++){
            it->second=pn;
            pn++;
        }
        memset(par,0,sizeof(par));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            par[Re[arr[i]]][Re[dep[i]]]=1;

        ans=1;
        for(i=0;i<=pn;i++)
            for(j=0;i+j<=pn;j++){
                if(i)
                    dp[j][j+i]=max(dp[j+1][j+i],dp[j][j+i-1]);
                for(k=j;k<j+i;k++)
                    dp[j][j+i]=max(dp[j][j+i],dp[j][k]+dp[k][j+i]);
                dp[j][j+i]+=par[j][j+i];
                ans=max(ans,dp[j][j+i]);
            }

        printf("%d\n",ans);
    }

    return 0;
}
