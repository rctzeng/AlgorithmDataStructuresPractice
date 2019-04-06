#include <stdio.h>
#include <string.h>

#define MAX 5001

int main() {

    int n;
    int C[3][MAX];

    while(scanf("%d", &n) != EOF) {
        memset(C, sizeof(C), 0);
        int t;
        int n1=0,n2=0,n3=0;
        for(int i=1;i<=n;i++) {
            scanf("%d", &t);
            switch(t) {
                case 1:
                    C[0][n1++]=i;
                    break;
                case 2:
                    C[1][n2++]=i;
                    break;
                case 3:
                    C[2][n3++]=i;
                    break;
            }
        }

        int sc = -1;
        int sn = MAX;
        if (n1<n2) {
            sc = 1;sn = n1;
        } else {
            sc = 2;sn = n2;
        }

        if (n3<sn) {
            sc = 3;sn = n3;
        }

        if (sn == 0)
            printf("0\n");
        else {
            printf("%d\n", sn);
            for(int i=0;i<sn;i++) {
                for(int j=0;j<3;j++) {
                    printf("%d", C[j][i]);
                    if(j!=2)    printf(" ");
                    else    printf("\n");
                }
            }
        }
    }

    return 0;
}
