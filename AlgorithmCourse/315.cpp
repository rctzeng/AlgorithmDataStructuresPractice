#include <stdio.h>
#include <string.h>

#define min(x,y) (x)<(y)?(x):(y)
#define MAX 101

int g[MAX][MAX];
int low[MAX], d[MAX];
int v[MAX];

int N, C;

int dfs(int now, int p, int dep);

int main() {
    while (~scanf("%d", &N) && N) {
        memset(g,0,sizeof(g));
        memset(v,0,sizeof(v));

        int p1, p2;
        while (~scanf("%d", &p1) && p1) {
            char c;
            while (~scanf("%d%c", &p2, &c)) {
                g[p1][p2]=g[p2][p1]=1;
                if (c == '\n')  break;
            }
        }

        C=0;
        dfs(1,1,0);

        printf("%d\n",C);
    }

    return 0;
}

int dfs(int now, int p, int dep) {
    v[now]=1;
    low[now]=dep;
    d[now]=dep;

    int f=0;
    int child=0;
    for (int i=1;i<=N;i++) {
        if (g[i][now] == 1 && i!=p) {
            if (!v[i]) {
                v[i]=1;
                int t = dfs(i,now,dep+1);
                if (t>=dep) f=1;
                low[now]=min(low[now], t);

                child++;
            } else {
                //low[now] = min(low[now], d[i]);
            }
        }
    }

    // root cannot be endpoint
    if ((now == p && child>1)||(now != p && f))
        C++;

    return low[now];
}
