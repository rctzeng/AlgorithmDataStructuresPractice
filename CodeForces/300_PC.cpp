#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100001

int OK, Max;
void check(int d1, int d2, int h1, int h2);

int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    int d[MAX];
    int h[MAX];
    for(int i=0;i<m;i++)    scanf("%d%d", &d[i], &h[i]);
    OK = 1;
    Max = 0;
    for(int i=1;i<m && OK;i++)
        check(d[i-1],d[i],h[i-1],h[i]);

    if(OK>0)    printf("%d\n", Max);
    else    printf("IMPOSSIBLE\n");

    return 0;
}

void check(int d1, int d2, int h1, int h2) {
    int hd = abs(h1-h2);
    int dd = abs(d1-d2);
    if(hd>dd)   OK = -1;
    else {
        int l = h1<h2?h1:h2;
        int r = l+(hd+dd)/2;
        Max = Max>r?Max:r;
    }
}
