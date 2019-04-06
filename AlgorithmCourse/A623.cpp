#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2568

int num[MAX], digit;

void mul(int i);

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d!\n", n);
        memset(num, 0, sizeof(num));
        num[0]=1;
        digit=1;
        for(int i=1;i<=n;i++)
            mul(i);

        for(int i=digit-1;i>=0;i--)
            printf("%d", num[i]);
        printf("\n");
    }

    return 0;
}

void mul(int i) {
    for(int j=0;j<digit;j++)
        num[j]*=i;

    int c=0,mt;
    for(int j=0;j<digit;j++) {
        mt=(c+num[j]);
        c=mt/10;
        num[j]=mt%10;
    }
    while(c) {
        num[digit] = c%10;
        c = c/10;
        digit++;
    }
}
