#include<stdio.h>

#define MAX 1000000

int prime[MAX];

int main(){
    int n,a,i,j,f;

    prime[0]=1;prime[1]=1;prime[2]=0;
    for(i=2;i<=MAX;i++)
        if(!prime[i])
            for(j=i+i;j<=MAX;j+=i)
                prime[j]=1;

    while(~scanf("%d", &n)&&n){
        f=1;
        for(a=2;a<n;a++)
            if(!prime[a] && !prime[n-a]){
                printf("%d = %d + %d\n",n,a,n-a);
                f=0;
                break;
            }
        if(f)   printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
