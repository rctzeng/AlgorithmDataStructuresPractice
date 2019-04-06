#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

#define MAX 26
#define cMAX 1<<20
#define min(x,y) (x)<(y)?(x):(y)

using namespace std;

typedef struct node{
    char pattern[MAX];
    int num;
}node;

int drc[8][2]={{-1,-2},{-2,-1},{-1,2},{2,-1},{-2,1},{1,-2},{1,2},{2,1}};
node init, targt;
node sBFS[cMAX], eBFS[cMAX];
int sn, en;
set<int> svis, evis;

void bfs(int se);
void copyNode(node *a, node *b);
int insertNode(int n, int se);
int calc(char *s);
int findSpace(char *s);
int cmp(const void *a, const void *b);

int main() {
    //freopen("10422.in", "r", stdin);
    //freopen("out.txt", "w+", stdout);
    int T;
    scanf("%d\n", &T);
    strcpy(init.pattern, "111110111100 110000100000");
    while(T--) {
        svis.clear();
        evis.clear();
        targt.pattern[0]='\0';
        char temp[MAX];
        for (int i=0;i<5;i++) {
            gets(temp);
            for (int j=0;j<5;j++)
                targt.pattern[i*5+j]=temp[j];
        }
        targt.num=0;
        init.num=0;
        copyNode(&sBFS[0],&init);
        copyNode(&eBFS[0],&targt);
        sn=en=1;
        bfs(0);
        bfs(1);
        qsort(sBFS, sn, sizeof(node), cmp);
        qsort(eBFS, en, sizeof(node), cmp);
        int fd=-1;
        for (int i=0;i<sn;i++) {
            int si = calc(sBFS[i].pattern);
            int s=0;
            int e=en;
            while(s<e) {
                int mid=(s+e)/2;
                int mi=calc(eBFS[mid].pattern);
                if (mi<si) s=mid+1;
                else if(mi>si) e=mid;
                else {
                    int cp = strcmp(sBFS[i].pattern,eBFS[mid].pattern);
                    if (cp<0)   s=mid+1;
                    else if(cp>0)   e=mid;
                    else {
                        int now=sBFS[i].num+eBFS[mid].num;
                        if(fd==-1)  fd=now;
                        else    fd=min(fd,now);
                        break;
                    }
                }
            }
        }

        if (fd!=-1 && fd<11)
            printf("Solvable in %d move(s).\n", fd);
        else    puts("Unsolvable in less than 11 move(s).");
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    node c = *(node *)a;
    node d = *(node *)b;
    int ai = calc(c.pattern);
    int bi = calc(d.pattern);
    if (ai != bi)    return ai-bi;
    return strcmp(c.pattern,d.pattern);
}

int calc(char *s) {
    int r=0;
    for (int i=0;i<25;i++) {
        switch(s[i]) {
        case '0':
            r=r*2;
            break;
        case '1':
            r=r*2+1;
            break;
        case ' ':
            r=r*2+2;
            break;
        }
    }
    return r;
}

int insertNode(int cal, int se) {
    int h=-1;
    switch (se) {
    case 0:
        if (svis.count(cal))  return 0;
        svis.insert(cal);
        return 1;
        break;
    case 1:
        if (evis.count(cal))  return 0;
        evis.insert(cal);
        return 1;
        break;
    }
    return 0;
}

void bfs(int se) {
    switch(se) {
    case 0:
        for (int i=0;i<sn;i++) {
            if (sBFS[i].num < 6) {
                char temp[MAX];
                int space = findSpace(sBFS[i].pattern);
                int r=space/5;
                int c=space%5;
                for (int j=0;j<8;j++) {
                    strcpy(temp,sBFS[i].pattern);
                    if ((r+drc[j][0])>=0&&(r+drc[j][0])<5 && (c+drc[j][1])>=0&&(c+drc[j][1])<5) {
                        temp[space]=temp[(r+drc[j][0])*5+c+drc[j][1]];
                        temp[(r+drc[j][0])*5+c+drc[j][1]]=' ';
                        if (insertNode(calc(temp), 0)==1) {
                            strcpy(sBFS[sn].pattern, temp);
                            sBFS[sn].num=sBFS[i].num+1;
                            sn++;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        for (int i=0;i<en;i++) {
            if (eBFS[i].num < 6) {
                char temp[MAX];
                int space = findSpace(eBFS[i].pattern);
                int r=space/5;
                int c=space%5;
                for (int j=0;j<8;j++) {
                    strcpy(temp,eBFS[i].pattern);
                    if ((r+drc[j][0])>=0&&(r+drc[j][0])<5 && (c+drc[j][1])>=0&&(c+drc[j][1])<5) {
                        temp[space]=temp[(r+drc[j][0])*5+c+drc[j][1]];
                        temp[(r+drc[j][0])*5+c+drc[j][1]]=' ';
                        if (insertNode(calc(temp), 1)==1) {
                            strcpy(eBFS[en].pattern, temp);
                            eBFS[en].num=eBFS[i].num+1;
                            en++;
                        }
                    }
                }
            }
        }
        break;
    }
}

int findSpace(char *s) {
    int r = -1;
    for (int i=0;i<25;i++)  {
        if (s[i]==' ') {
            r=i;
            break;
        }
    }
    return r;
}

void copyNode(node *a, node *b) {
    *a = *b;
}
