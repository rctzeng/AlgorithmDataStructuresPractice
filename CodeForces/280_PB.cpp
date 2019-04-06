#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

#define max(x,y) (x)>(y)?(x):(y)

int A[MAX];

int cmp(const void *a,const void *b) {
    return *(int *)a-*(int *)b;
}
int abs(int k) {
    if(k<0) return -k;
    return k;
}

int main() {

    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    qsort(A,n,sizeof(int),cmp);
    int ml=0;
    for(int i=0;i<n;i++) {
        if(i+1<n) ml=max(ml,abs(A[i+1]-A[i]));
    }
    double ans=(double)ml/2.0;
    ans=max(ans,A[0]);
    ans=max(ans,abs(l-A[n-1]));

    printf("%.11lf\n", ans);

    return 0;
}
