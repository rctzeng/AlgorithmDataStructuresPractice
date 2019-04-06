#include <stdio.h>
#include <stdlib.h>

#define nMAX 1000001
#define MAX 1001

typedef struct node {
    int x;
    int y;
    int s;
}node;

int S[MAX];
int l,r,index;
node E[nMAX];

int cmp(const void *a, const void *b) {
    node c = *(node *)a;
    node d = *(node *)b;
    return c.s - d.s;
}

int cmp1(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int Bsearch(int t);

int main() {
    int n;
    while(scanf("%d", &n)!=EOF &&n) {
        int a,b,c,d;
        for(int i=0;i<n;i++)    scanf("%d",&S[i]);
        qsort(S, n, sizeof(int), cmp1);
        index=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) {
                E[index].x=S[i];
                E[index].y=S[j];
                E[index++].s=S[i]+S[j];
            }
        qsort(E, index, sizeof(node), cmp);
        int f=0;
        for(int i=0;i<n &&!f;i++) {
            for(int j=0;j<n &&!f;j++) {
                if(i!=j) {
                    for(int k=0;k<index &&!f;k++) {
                        if(E[k].s==S[i]-S[j]) {
                            if(E[k].x!=S[i] && E[k].y!=S[i] && E[k].x!=S[j] &&E[k].y!=S[j]) {
                                printf("%d\n", S[i]);
                                f=1;
                                break;
                            }
                        }else if(E[k].s>S[i]+S[j])  break;
                    }
                }
            }
        }
        if(!f)  printf("no solution\n");


    }

    return 0;
}
