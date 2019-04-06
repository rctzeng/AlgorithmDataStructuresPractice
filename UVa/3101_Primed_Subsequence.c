#include<stdio.h>

#define MAX 100001

int isprime[MAX],prime[MAX],primeL;
int num[MAX],pre[MAX];

int main(){
    int i,j,T,l,k,n,f;
    isprime[0]=1;isprime[1]=1;isprime[2]=0;
    primeL=0;
    for(i=2;i<=MAX;i++)
        if(!isprime[i]){
            prime[primeL++]=i;
            for(j=i+i;j<=MAX;j+=i)
                isprime[j]=1;
        }

    scanf("%d",&T);
    while(T--){
        scanf("%d",&l);
        num[0]=pre[0]=0;
        for(i=1;i<=l;i++){
            scanf("%d", &num[i]);
            pre[i]=pre[i-1]+num[i];
        }

        f=0;
        for(i=2;i<=l && !f;i++){
            for(j=0;i+j<=l;j++){
                n=pre[i+j]-pre[j];
                if(n<MAX){
                    if(!isprime[n])
                        f=1;
                } else{
                    for(k=0;k<primeL;k++)
                        if(!(n%prime[k]))
                            f=1;
                }
                if(f){
                    printf("Shortest primed subsequence is length %d:", i);
                    for(k=j+1;k<=i+j;k++)    printf(" %d",num[k]);
                    printf("\n");
                    break;
                }
            }
        }
        if(!f)  printf("This sequence is anti-primed.\n");
    }

    return 0;
}
