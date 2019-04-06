#include <stdio.h>
#include <string.h>

#define MAX 10001

int prime[MAX];
int is_prime[MAX]; // 1: not prime, 0: is prime
int div[MAX];

int main() {
    memset(is_prime, 0, sizeof(is_prime));
    is_prime[1]=1;
    int cp=0;
    for(int i=2;i<MAX;i++) {
        if(!is_prime[i]) {
            prime[cp++]=i;
            for(int j=i+i;j<MAX;j+=i)
                is_prime[j]=1;
        }
    }

    int T;
    scanf("%d", &T);
    int L, U;
    while(T--) {
        scanf("%d%d", &L, &U);
        int largest=0, ans=L;
        for(int i=L;i<=U;i++) {
            memset(div, 0, sizeof(div));
            int t=i;
            int j=0;
            while(j<cp) {
                if(!(t%prime[j])) {
                    t/=prime[j];
                    div[j]++;
                } else j++;
            }
            int dnum=1;
            for(int k=0;k<cp;k++)
                dnum *= (div[k]+1);
            if(t>1) dnum*=2;
            if(dnum > largest) {
                largest=dnum;
                ans=i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, ans, largest);
    }

    return 0;
}
