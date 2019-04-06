#include<stdio.h>

#define MAX 100001
#define NMAX 1299710

int isprime[NMAX], prime[MAX];

int main(){
    int i,j,l;
    l=0;
    for(i=2;i<NMAX;i++){
        if(!isprime[i]){
            prime[l++]=i;
            for(j=i+i;j<NMAX;j+=i)
                isprime[j]=1;
        }else   isprime[i]=l;
    }
    int n;
    while(~scanf("%d",&n)&&n){
        if(!isprime[n])   printf("0\n");
        else    printf("%d\n",prime[isprime[n]]-prime[isprime[n]-1]);
    }
    return 0;
}
