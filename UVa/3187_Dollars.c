#include<stdio.h>
#include<string.h>

#define MAX 10001

int Coin[11]={1,2,4,10,20,40,100,200,400,1000,2000};
long long int Ways[MAX];

int main(){
    double d;
    int dollar,i,j,n;
    memset(Ways,0,sizeof(Ways));
    Ways[0]=1;
    for(i=0;i<11;i++)
        for(j=Coin[i];j<MAX;j++)
            Ways[j]+=Ways[j-Coin[i]];

    while(~scanf("%lf",&d)){
        dollar=20*d+0.5;
        if(dollar==0)   break;
        printf("%6.2lf%17lld\n",d,Ways[dollar]);
    }

    return 0;
}
