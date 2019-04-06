#include<stdio.h>

#define MAX 1001

int Length[MAX];

int main(){
    int i,n;
    double tl;
    Length[0]=0;
    for(i=1;i<MAX;i++){
        tl+=100/(double)(i+1);
        Length[i]=tl;
    }

    while(scanf("%lf",&tl)){
        n=100*tl;
        if(n==0)    break;
        for(i=1;i<MAX;i++)
            if(n<=Length[i])
                break;
        printf("%d card(s)\n",i);
    }

    return 0;
}
