#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define MAX 10001

int Num[MAX];

void check(int *top, int i,int *S, int *D);

int main(){
    int N,i,ii,topI,topD,M;
    int stackI[MAX],stackD[MAX],dpI[MAX],dpD[MAX];
    while(~scanf("%d",&N)){
        for(i=0;i<N;i++)    scanf("%d",&Num[i]),dpI[i]=dpD[i]=1;
        topI=topD=0;stackI[0]=stackD[0]=-1;
        for(i=0,ii=N-1;i<N;i++,ii--){
            check(&topI,i,stackI,dpI);
            check(&topD,ii,stackD,dpD);
        }

        M=0;
        for(i=0;i<N;i++)    M=max(M,min(dpI[i],dpD[i]));

        printf("%d\n",M*2-1);
    }

    return 0;
}

void check(int *top, int i, int *S, int *D){
    if(Num[i]>S[*top]){
        *top=*top+1;
        S[*top]=Num[i];
        D[i]=*top;
    }else{
        int l=1,r=*top,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(Num[i]>S[mid])   l=mid+1;
            else    r=mid-1;
        }
        S[l]=Num[i];
        D[i]=*top;
    }
}
