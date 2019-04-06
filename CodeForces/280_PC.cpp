#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
#define min(x,y) (x)<(y)?(x):(y)

typedef struct node{
    int a;
    int b;
}node;

node G[MAX];

int cmp(const void *a,const void *b) {
    node c = *(node *)a;
    node d = *(node *)b;
    return c.b-d.b;
}

int main() {
    int n,r,avg;
    scanf("%d%d%d",&n,&r,&avg);
    for(int i=0;i<n;i++)
        scanf("%d%d",&G[i].a,&G[i].b);

    qsort(G,n,sizeof(node),cmp);
    long long int gap = (long long int)avg*n;
    for(int i=0;i<n;i++)    gap-=G[i].a;
    long long int essay=0;
    for(int i=0;i<n&&gap>0;i++) {
        int d=r-G[i].a;
        if(d>0) {
            int inc=min(d,gap);
            essay+=(long long int)inc*(G[i].b);
            gap-=d;
        }
    }

    printf("%I64d\n",essay);

    return 0;
}
