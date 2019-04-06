#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    int d[7];
    int l=0;
    int md=0;
    while(num) {
        int dt = num%10;
        d[l++] = dt;
        num /= 10;
        md = md>dt?md:dt;
    }

    printf("%d\n", md);
    for(int i=0;i<md;i++) {
        if(i)   printf(" ");
        int lz=-1;
        for(int j=l-1;j>=0;j--) {
            if(d[j]) {
                d[j]--;
                lz = 1;
                printf("1");
            } else if(lz>0) {
                printf("0");
            }
        }
    }
    printf("\n");

    return 0;
}
