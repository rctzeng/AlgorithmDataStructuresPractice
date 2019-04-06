#include <stdio.h>

#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

int main() {
    freopen("D-large-practice.in", "r", stdin);
    freopen("outD.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int X,R,C;
        scanf("%d%d%d", &X, &R, &C);
        if(((R*C)%X)!=0)  printf("Case #%d: RICHARD\n", t);
        else {
            int M = max(R,C);
            int m = min(R,C);
            if((X==3 && M*m==3)||(X==4 && m<=2)||(X==5 && (m<=2||(M==5 && m==3)))||(X==6 && m<=3)||X>=7) printf("Case #%d: RICHARD\n", t);
            else printf("Case #%d: GABRIEL\n", t);
        }
    }

    return 0;
}
