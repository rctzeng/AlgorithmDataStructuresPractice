#include <stdio.h>
#include <string.h>

#define MAX 26

char name[MAX][MAX];
int Map[MAX][MAX];
int use[MAX];

int main() {
    int n, m;
    int T=0;
    while (scanf("%d%d", &n, &m)==2 && (n+m)) {
        int t=0;
        char s1[MAX], s2[MAX];
        int n1, n2;
        memset(Map,0,sizeof(Map));
        for (int i=0;i<m;i++) {
            scanf("%s%s", s1, s2);
            n1=-1;n2=-1;
            for (int j=0;j<t;j++) {
                if (strcmp(s1,name[j])==0) n1=j;
                if (strcmp(s2,name[j])==0) n2=j;
            }
            if (n1==-1) {
                strcpy(name[t],s1);
                n1=t;
                t++;
            }
             if (n2==-1) {
                strcpy(name[t],s2);
                n2=t;
                t++;
            }
            Map[n1][n2]=1;
        }

        for (int k=0;k<t;k++)
            for (int i=0;i<t;i++)
                for (int j=0;j<t;j++)
                    Map[i][j]=Map[i][j]||(Map[i][k]&&Map[k][j]);

        printf("Calling circles for data set %d:\n", ++T);
        memset(use,0,sizeof(use));
        for (int i=0;i<t;i++) {
            int f=0;
            if (!use[i]) {
                use[i]=1;
                printf("%s", name[i]);
                f=1;
            }

            for (int j=0;j<t;j++) {
                if (Map[i][j] && Map[j][i] && !use[j]) {
                    use[j]=1;
                    printf(", %s", name[j]);
                }
            }

            if (f)
                puts("");
        }
    }

    return 0;
}
