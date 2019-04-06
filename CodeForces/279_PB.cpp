#include <stdio.h>
#include <string.h>

#define MAX 1000001
#define nMAX 200001

int appear[MAX];
int next[nMAX];
int pre[nMAX];
int node[nMAX];

int main() {
    memset(next,sizeof(next),0);
    memset(pre,sizeof(pre),0);
    memset(appear,sizeof(appear),0);
    int n;
    scanf("%d", &n);
    int ni=1;
    int a,b;
    for(int i=0;i<n;i++) {
        scanf("%d%d", &a,&b);
        // relabel
        if(a!=0 && appear[a]==0) {
            node[ni++]=a;
            appear[a]=ni-1;
        }
        if(b!=0 && appear[b]==0) {
            node[ni++]=b;
            appear[b]=ni-1;
        }

        if(a==0) pre[appear[b]]=-2;
        if(b==0) next[appear[a]]=-2;
        if(a!=0 && b!=0) {
            next[appear[a]]=appear[b];
            pre[appear[b]]=appear[a];
        }
    }

    int qs=-1,qe=-1,s=-1,e=-1;
    for(int i=1;i<ni;i++) {
        if(pre[i]==0)  qs=i;
        if(next[i]==0) qe=i;
        if(pre[i]==-2)  s=i;
        if(next[i]==-2) e=i;
    }

    if(n%2) {
        printf("%d", node[qs]);
        qs=next[qs];
        while(qs!=0) {
            printf(" %d %d", node[s],node[qs]);
            qs=next[qs];
            s=next[s];
        }
        printf("\n");
    } else {
        printf("%d %d", node[qs],node[s]);
        qs=next[qs];
        s=next[s];
        while(qs!=-2) {
            printf(" %d %d", node[qs],node[s]);
            qs=next[qs];
            s=next[s];
        }
        printf("\n");
    }

    return 0;
}
