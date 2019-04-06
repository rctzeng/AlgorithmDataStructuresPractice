#include<stdio.h>
#include<stdlib.h>

#define max(x,y) (x)>(y)?(x):(y)
#define MAX 10001

typedef struct node{
    int num,h;
}node;

node Skii_Area[MAX];
int h[MAX],dp[MAX];

int cmp(const void *a,const void *b){
    node c=*(node *)a;
    node d=*(node *)b;
    return c.h-d.h;
}

int main(){
    int R,C,i,j,A,m,ans,n,hight;
    while(~scanf("%d%d",&R,&C)){
        A=R*C;
        for(i=0;i<A;i++){
            scanf("%d",&h[i]),dp[i]=1;
            Skii_Area[i].h=h[i];
            Skii_Area[i].num=i;
        }
        qsort(Skii_Area,A,sizeof(node),cmp);

        ans=0;
        for(i=0;i<A;i++){
            n=Skii_Area[i].num;
            hight=Skii_Area[i].h;
            m=dp[n];
            if(n+C<A && h[n+C]<hight)   m=max(m,dp[n+C]+1);
            if(n+1<A &&(n+1)%C>n%C && h[n+1]<hight) m=max(m,dp[n+1]+1);
            if((n-C)>=0 && h[n-C]<hight)    m=max(m,dp[n-C]+1);
            if(n-1>=0 &&(n-1)%C<n%C && h[n-1]<hight)    m=max(m,dp[n-1]+1);

            dp[n]=m;
            ans=max(ans,m);
        }

        printf("%d\n",ans);
    }
    return 0;
}
