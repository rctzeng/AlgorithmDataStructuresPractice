#include <stdio.h>
#include <string.h>

/**
do not know why press order matters:
    unpress, then press, then recover unpressed would do
    but press, then unpress cannot
**/

int Pattern[3][3];
int Press[6][6];
int Map[6][6];
int r,c;

int dfs(int now);
int checkR(int row);
int checkAll();
void press(int nr, int nc);
void print(int nr, int nc);

int main() {
    //freopen("10318.in", "r", stdin);
    //freopen("10318.txt", "w+", stdout);
    int T=0;
    while(~scanf("%d%d%*c", &r, &c)&& (r+c)) {
        memset(Map, 0, sizeof(Map));
        memset(Press, 0, sizeof(Press));
        memset(Pattern, 0, sizeof(Pattern));

        // read in pattern
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++)
                Pattern[i][j]=(getchar()=='*'?1:0);
            getchar();
        }

        printf("Case #%d\n", ++T);
        if (dfs(0)) {
            //print(r,c);
            int f=0;
            for (int i=0;i<r;i++)
                for (int j=0;j<c;j++)
                    if (Press[i][j]==1) {
                        if (f==0)   f=1;
                        else    printf(" ");
                        printf("%d", i*c+j+1);
                    }
            puts("");
        } else
            puts("Impossible.");
    }

    return 0;
}

int dfs(int now) {
    int nr = now/c;
    int nc = now%c;

    // check completed
    if (nr>=2 && checkR(nr-2)==0)
        return 0;
    if (nr>=r-2 || now==c*r) {
        if (checkAll()==1)
            return 1;
        if (now==c*r)
            return 0;
    }

    // not press (nr,nc)
    if (dfs(now+1))
        return 1;
    press(nr,nc);

    // press (nr,nc)
    if (dfs(now+1))
        return 1;
    press(nr,nc);

    return 0;
}

void press(int nr, int nc) {
    for (int i=nr-1;i<nr+2;i++)
        if (i>=0 && i<r)
            for (int j=nc-1;j<nc+2;j++)
                if (j>=0 && j<c)
                    if(Pattern[i-(nr-1)][j-(nc-1)]==1)
                        Map[i][j]=1-Map[i][j];

    Press[nr][nc]=1-Press[nr][nc];
}

int checkAll() {
    if (r>1)
        return checkR(r-1) && checkR(r-2);

    return checkR(r-1);
}

int checkR(int row) {
    for (int i=0;i<c;i++)
        if (Map[row][i]==0)
            return 0;
    return 1;
}

void print(int nr, int nc) {
    printf("-----(%d, %d)---------\n", nr, nc);
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++)
            printf("%d", Map[i][j]);
        printf("  ");
        for (int j=0;j<c;j++)
            printf("%d", Press[i][j]);
        puts("");
    }
    puts("--------------------");
}
