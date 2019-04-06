#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)
#define MAX 1001

int Ans[MAX],temp[MAX],l;

void Mul(int A);
void Add();

int main(){
    int A,N,i,j,k,msb,c,a;
    while(scanf("%d%d",&N,&A)==2){
        memset(Ans,0,sizeof(Ans));
        l=1;
        for(i=1;i<=N;i++){
            memset(temp,0,sizeof(temp));temp[0]=1;
            for(j=0;j<i;j++)
                Mul(A);
            Mul(i);
            Add();
        }

        for(i=l-1;i>=0;i--)
            printf("%d",Ans[i]);
        printf("\n");
    }

    return 0;
}

void Mul(int A){
    int i,ca,t,m;
    ca=0;m=0;
    for(i=0;i<l;i++){
        t=ca+A*temp[i];
        temp[i]=t%10;
        ca=t/10;
    }
    if(ca)  temp[i]+=ca, l=max(l,i+1);
    ca=0;
}
void Add(){
    int i,c,t;
    c=0;
    for(i=0;i<l;i++){
        t=Ans[i]+c+temp[i];
        Ans[i]=t%10;
        c=t/10;
    }
    if(c)   l=max(l,i+1),Ans[i]=c;
}
