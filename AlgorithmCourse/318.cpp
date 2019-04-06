#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAX 501
#define INF INT_MAX

int G[MAX][MAX];
int D[MAX];
int V[MAX];

int main() {

    int n, m;
    int t=0;
    while (~scanf("%d%d", &n, &m) && (n+m)) {
        memset(V, -1, sizeof(V));

        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                G[i][j]=G[j][i]=INF;

        int a, b, l;
        for (int i=0; i<m; i++) {
            scanf("%d%d%d", &a, &b, &l);
            G[a][b] = G[b][a] = l;
        }

        for (int i=1 ;i<=n; i++)
            D[i]=INF;
        // Djikstra
        D[1] = 0;
        for (int i=0; i<n; i++) {
            // find the least distant unvisit node
            int disLeast = -1;
            int dis = INF;
            for (int j=1; j<=n; j++) {
                if (V[j]==-1 && D[j] < dis) {
                    disLeast = j;
                    dis = D[j];
                }
            }

            V[disLeast] = 1;
            // relax
            for (int j=1; j<=n; j++)
                if (G[disLeast][j] < INF)
                    if (G[disLeast][j] + D[disLeast] < D[j])
                        D[j] = G[disLeast][j] + D[disLeast];
        }

        double maxTime = -1;
        int one = -1;
        int t1=-1, t2=-1;
        double m;
        for (int i=1; i<=n; i++) {
            if (maxTime < D[i]) {
                maxTime = D[i];
                one = i;
                t1 = t2 = -1;
            }
        }

        // calculate exactly fall down time between nodes
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (G[i][j] < INF) {
                    m = (double)(G[i][j]+D[i]+D[j])/2;
                    if (m > maxTime) {
                        maxTime = m;
                        one = -1;
                        t1 = i;
                        t2 = j;
                    }
                }
            }
        }

        printf("System #%d\n", ++t);
       if (one != -1)
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n", maxTime, one);
        else printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n", maxTime, t1, t2);
        puts("");
    }

    return 0;
}
