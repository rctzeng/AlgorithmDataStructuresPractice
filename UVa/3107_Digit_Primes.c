#include<stdio.h>

#define MAX 1000001

int prime[MAX];
int prime_sum[MAX];

int main(){
    int i,j,d,ds;
    prime_sum[1]=0;
    for(i=2;i<MAX;i++){
        if(!prime[i]){
            for(j=i+i;j<MAX;j+=i)   prime[j]=1;
            d=i;ds=0;
            while(d>0){
                ds+=d%10;
                d/=10;
            }
            if(!prime[ds])
                prime_sum[i]=prime_sum[i-1]+1;
            else    prime_sum[i]=prime_sum[i-1];
        }else
            prime_sum[i]=prime_sum[i-1];
    }

    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d\n",prime_sum[b]-prime_sum[a-1]);
    }
    return 0;
}
