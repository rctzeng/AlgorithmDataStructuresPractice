#include <stdio.h>
#include <string.h>

#define MAX 30001
#define sMAX 1000001

int P[MAX];
int Node[sMAX];
int Next[sMAX];

int visit[MAX];
int v[MAX];

void addEdge (int p1, int p2, int num);
void dfs(int p);

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d%d", &N, &M);

        memset(P,-1,sizeof(P));
        memset(Node,-1,sizeof(Node));
        memset(Next,-1,sizeof(Next));
        int p1, p2;
        for (int i=0;i<M;i++) {
            scanf("%d%d", &p1, &p2);
            addEdge(p1,p2,i);
        }

        int n=0;
        memset(visit,0,sizeof(visit));
        for (int i=1;i<=N;i++) {
            if (!visit[i]) {
                memset(v,0,sizeof(v));
                dfs(i);
                int c=0;
                for (int j=1;j<=N;j++) {
                    if (v[j])
                        c++;
                }
                if (c>n)    n=c;
            }
        }

        printf("%d\n", n);
    }

    return 0;
}

void addEdge (int p1, int p2, int num) {
    Node[num*2] = p2;
    Next[num*2] = -1;
    Node[num*2+1] = p1;
    Next[num*2+1] = -1;
    if (P[p1]<0) {
        P[p1] = num*2;
    } else {
        int t = P[p1];
        while (Next[t]>=0)
            t = Next[t];
        Next[t] = num*2;
    }

    if (P[p2]<0) {
        P[p2] = num*2+1;
    } else {
        int t = P[p2];
        while (Next[t]>=0)
            t = Next[t];
        Next[t] = num*2+1;
    }
}

void dfs(int p) {
    visit[p]=1;
    v[p]=1;
    int t = P[p];
    while (t>=0) {
        if (!v[Node[t]])
            dfs(Node[t]);

        t = Next[t];
    }
}
