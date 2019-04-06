#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define MAX 10001

using namespace std;

typedef struct node{
    int top, bot;
    int rev;
}node;

node Node[MAX];

int dp[MAX][MAX];

int cmp(const void *a,const void *b){
    node c=*(node *)a;
    node d=*(node *)b;
    return c.top-d.top;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int L,P,a,b,pn=0,sn=0;
        scanf("%d%d",&L,&P);
        for(int j=0;j<P;j++){
            scanf("%d%d",&a,&b);
            Node[pn].top=a,Node[pn].bot=b;Node[pn++].rev=1;
            Node[pn].top=b,Node[pn].bot=a;Node[pn++].rev=-1;
        }
        qsort(Node,pn,sizeof(node),cmp);
        memset(dp,0,sizeof(dp));

        for(int l=1;l<pn;l++){
            for(int j=0;j+l<pn;j++){
                if(!dp[j][j+l]){
                    if(l==1&&(Node[j].rev==Node[j+l].rev||(Node[j].top==Node[j+l].bot&&Node[j].bot==Node[j+l].top)))
                        dp[j][j+l]=1;
                    if(l>2){
                        if(dp[j+1][j+l-1])
                            if((Node[j].top==Node[j+l].bot&&Node[j].bot==Node[j+l].top)||(Node[j].rev==Node[j+l].rev)){
                                dp[j][j+l]=1;
                            }
                        if(!dp[j][j+l]){
                            for(int k=j+1;k<j+l&&!dp[j][j+l];k++){
                                if(dp[j][k]&&dp[k+1][j+l])
                                    dp[j][j+l]=1;
                            }
                        }
                    }
                }
            }
        }

        if(dp[0][pn-1])  puts("YES");
        else    puts("NO");
    }

    return 0;
}
