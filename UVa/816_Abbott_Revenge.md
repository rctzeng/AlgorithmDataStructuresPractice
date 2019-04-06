# UVa 816 Abbott's Revenge
## Solve
分點, 每個點複製四分(分別表示從 N,E,S,W 進入)
```
#include <stdio.h>
#include <string.h>

#define MAX 10001

char Direc[4] = {'U', 'R', 'D', 'L'};
int DOP[4][2] = {{-1, 0}, {0, 1}, {1,0}, {0, -1}};

typedef struct node {
    int d[4][4];
}node;

typedef struct qnode {
    int x, y;
    int in;
}qnode;

node Map[10][10];
qnode que[MAX];
int qparent[MAX];
int visit[10][10][4][4];

int convert(char c);
int convRLF(int now, char c);
void printMap();
int check (int x, int y, int in, int d);

int main() {

    char Name[500];
    while (gets(Name)!=NULL) {
        if (strcmp(Name, "END")==0) break;

        memset(Map, 0, sizeof(Map));
        memset(qparent, -1, sizeof(qparent));
        memset(visit, 0, sizeof(visit));

        int sx, sy, sd, ex, ey;
        char cd[4];
        // read start point, and end point
        scanf("%d%d%s%d%d", &sy, &sx, cd, &ey, &ex);
        sd = convert(cd[0]);

        int px, py;
        while (scanf("%d%d", &py, &px)==2) {
            char s[5];
            while (scanf("%s", s)!=EOF) {
                if (s[0]=='*')
                    break;

                int ln = strlen(s);
                int now = convert(s[0]);
                if (ln>1) {
                    int con = convRLF(now, s[1]);
                    Map[py][px].d[now][con]=1;
                }

                if (ln>2) {
                    int con = convRLF(now, s[2]);
                    Map[py][px].d[now][con]=1;
                }

                if (ln>3) {
                    int con = convRLF(now, s[3]);
                    Map[py][px].d[now][con]=1;
                }
            }
        }

        // BFS
        int f=0;
        int fn=-1;
        int qn = 1;
        que[0].x=sx;
        que[0].y=sy;
        que[0].in=sd;
        for (int i=0;i<qn;i++) {
            int nx, ny, nd;
            nx=que[i].x;
            ny=que[i].y;
            nd=que[i].in;

            int nxx=nx+DOP[nd][1];
            int nyy=ny+DOP[nd][0];

            if (nxx==ex && nyy==ey) {
                f=1;
                fn=i;
                break;
            }

            for (int a=0;a<4;a++) {
                if (check(nxx,nyy,nd,a)==1) {
                    if (Map[nyy][nxx].d[nd][a]==1) {
                        que[qn].x=nxx;
                        que[qn].y=nyy;
                        que[qn].in=a;
                        visit[nyy][nxx][nd][a]=1;
                        qparent[qn++]=i;
                    }
                }
            }
        }

        printf("%s\n", Name);
        if (f==1) {
            int nn=0;
            int Stack[401];
            int st=fn;
            while(st!=-1) {
                Stack[nn++]=st;
                st=qparent[st];
            }

            int Ans[401];
            // reverse
            for (int i=nn-1;i>=0;i--)
                Ans[nn-1-i]=Stack[i];
            printf("  ");
            for (int i=0;i<nn;i++) {
                printf("(%d,%d)", que[Ans[i]].y, que[Ans[i]].x);
                if (!((i+1)%10))    printf("\n  ");
                else    printf(" ");
            }

            printf("(%d,%d)", ey, ex);
            puts("");

        } else  puts("  No Solution Possible");
    }


    return 0;
}

int convert(char c) {

    switch (c) {
        case 'N':
            return 0;
            break;
        case 'E':
            return 1;
            break;
        case 'S':
            return 2;
            break;
        case 'W':
            return 3;
            break;
    }
}

int convRLF(int now, char c) {
    switch (c) {
        case 'F':
            return  now;
            break;
        case 'R':
            return (now+1)%4;
            break;
        case 'L':
            return (now+3)%4;
            break;
    }
}

void printMap() {
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            printf("(%d %d) ", j, i);
            for (int d=0;d<4;d++) {
                printf("%c: ", Direc[d]);
                for (int c=0;c<4;c++)
                    if (Map[j][i].d[d][c]==1)   printf("%c", Direc[c]);
                printf(" ");
            }
            puts("");
        }
    }
}

int check (int x, int y, int in, int d) {
    if (x>0&&x<10&&y>0&&y<10 && Map[y][x].d[in][d]==1) {
        if (visit[y][x][in][d]==0)
            return 1;
        return 0;
    }

    return 0;
}
```
