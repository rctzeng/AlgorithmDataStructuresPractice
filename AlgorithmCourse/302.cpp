#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

#define MAX 4000

typedef struct S {
   int x;
   int y;
   int z;
}S;

int used[MAX], added[MAX];
int Rlabel[MAX];
int N[MAX], node[MAX], in[MAX], next[MAX];
int check[MAX][2];
int ans[MAX];
int num, Snum, anum;

S forSort[MAX];

int Stack[MAX];

void add (int x, int y, int z, int n);
void dfs (int p, int np);
int cmp (const void *a, const void *b);

int main() {
    int x, y, z, john;
    while (~scanf("%d%d", &x, &y) && (x+y)) {
        num = 0;
        memset(N,-1,sizeof(N));
        memset(next,-1,sizeof(next));
        memset(used,-1,sizeof(used));
        memset(check,-1,sizeof(check));
        memset(added, -1, sizeof(added));

        // read input
        scanf("%d", &z);
        forSort[num].x=x;
        forSort[num].y=y;
        forSort[num].z=z;
        john=z;
        num++;
        while (~scanf("%d%d", &x, &y) && (x+y)) {
            scanf("%d", &z);
            forSort[num].x=x;
            forSort[num].y=y;
            forSort[num].z=z;
            num++;
        }

        // sort by edge number
        qsort(forSort, num, sizeof(S), cmp);

        // get input
        for (int i=0; i<num; i++) {
            add(forSort[i].x, forSort[i].y, forSort[i].z, i);
            check[forSort[i].z][0]=forSort[i].x;
            check[forSort[i].z][1]=forSort[i].y;
        }

        // relabel edge
        for (int i=0;i<num;i++)
            Rlabel[forSort[i].z] = i;

        // find euler path
        Snum=0;
        anum=0;
        dfs(min(forSort[Rlabel[john]].x, forSort[Rlabel[john]].y), forSort[Rlabel[john]].z);

        // check connectedness
        int l1, l2, n1, n2, f1;
        l1=min(forSort[Rlabel[Stack[Snum-1]]].x, forSort[Rlabel[Stack[Snum-1]]].y);
        l2=max(forSort[Rlabel[Stack[Snum-1]]].x, forSort[Rlabel[Stack[Snum-1]]].y);
        f1=l1;

        int f=0;
        // determine first node
        n1=forSort[Rlabel[Stack[Snum-2]]].x;
        n2=forSort[Rlabel[Stack[Snum-2]]].y;
        if (n1==l2) {
            f1=l1;
            l1=n1;
            l2=n2;
        } else if (n1==l1) {
            f1=l2;
            l1=n1;
            l2=n2;
        } else if (n2==l2) {
            f1=l1;
            l1=n2;
            l2=n1;
        } else if (n2==l1) {
            f1=l2;
            l1=n2;
            l2=n1;
        } else f=1;

        for (int i=Snum-3;i>=0 && !f;i--) {
            n1=forSort[Rlabel[Stack[i]]].x;
            n2=forSort[Rlabel[Stack[i]]].y;
            if (n1==l2) {
                l1=n1;
                l2=n2;
            } else if (n2==l2) {
                l1=n2;
                l2=n1;
            } else {
                f=1;
                break;
            }
        }

        if(f1!=l2)  f=1;

        if (f)  printf("Round trip does not exist.\n\n");
        else {
            for (int i=Snum-1;i>=0;i--) {
                printf("%d", Stack[i]);
                if (i)  printf(" ");
                else    printf("\n");
            }

            puts("");
        }
    }

    return 0;
}

void add (int x, int y, int z, int n) {
    node[n*2]=y;
    next[n*2]=-1;
    node[n*2+1]=x;
    next[n*2+1]=-1;

    in[n*2]=z;
    in[n*2+1]=z;

    if (N[x] == -1) {
        N[x]=n*2;
    } else {
        int t=N[x];
        while (next[t] != -1)
            t=next[t];

        next[t]=n*2;
    }

    if (N[y] == -1) {
        N[y]=n*2+1;
    } else {
        int t=N[y];
        while (next[t] != -1)
            t=next[t];

        next[t]=n*2+1;
    }
}

void dfs (int p, int np) {
    int t=N[p];
    while(t!=-1) {
        if(used[in[t]]==-1) {
            used[in[t]]=1;
            dfs (node[t], in[t]);
        }

        t=next[t];
    }

    if (added[np] == -1) {
        Stack[Snum++]=np;
        added[np]=1;
    }

    return;
}

int cmp (const void *a, const void *b) {
    S c = *(S *)a;
    S d = *(S *)b;
    return c.z-d.z;
}
