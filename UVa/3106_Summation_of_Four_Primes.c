#include<stdio.h>

#define MAX 10000001

int prime[MAX];

void GoldBach(int n);

int main(){
    int i,j;
    for(i=2;i<MAX;i++)
        if(!prime[i]){
            for(j=i+i;j<MAX;j+=i)
                prime[j]=1;
        }

    int n;
    while(~scanf("%d",&n)){
        if(n<8) printf("Impossible.\n");
        else{
            if(n%2){
                    printf("2 3");
                    GoldBach(n-5);
            }else{
                printf("2 2");
                GoldBach(n-4);
            }
        }
    }

    return 0;
}

void GoldBach(int n){
    int f=1,i;
    for(i=2;i<n;i++)
        if(!prime[i] && !prime[n-i]){
            printf(" %d %d\n",i,n-i);
            f=0;
            break;
        }
    if(f)   printf("Impossible.\n");
}
