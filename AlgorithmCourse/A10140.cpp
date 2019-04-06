#include <stdio.h>
#include <string.h>

#define MAX 50001

int prime[MAX];
int is_prime[MAX]; // 1: not prime, 0: is prime

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

    int L, U;
    while(scanf("%d%d", &L, &U)!=EOF) {
        int dmax=0, dmin=MAX;
        int dM1=-1, dM2=-1, dm1=-1, dm2=-1, plast=-1;
        for(int i=U;i>=L && i>1;i--) {
            int f=1;
            for(int j=0;j<cp && prime[j]*prime[j]<=i;j++)
                if(!(i%prime[j])) {
                    f=0;break;
                }
            if(!f)  continue;
            if(plast != -1) {
                if((plast-i) >= dmax) {
                    dM1=i;dM2=plast;dmax=plast-i;
                }
                if((plast-i) <= dmin) {
                    dm1=i;dm2=plast;dmin=plast-i;
                }
            }
            plast=i;
        }

        if(dm1!=-1)
            printf("%d,%d are closest, %d,%d are most distant.\n", dm1, dm2, dM1, dM2);
        else    printf("There are no adjacent primes.\n");
    }

    return 0;
}
