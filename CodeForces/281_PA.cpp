#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nMAX 21
#define MAX 100

typedef struct node{
    int m;
    int ha;
    int pn;
    int ry;
}node;

int play1[MAX];
int play2[MAX];
node Card[MAX];

int cmp(const void *a,const void *b) {
    node c=*(node *)a;
    node d=*(node *)b;
    return c.m-d.m;
}

int main() {
    memset(play1,0,sizeof(play1));
    memset(play2,0,sizeof(play2));
    char team1[nMAX];
    char team2[nMAX];
    scanf("%s",team1);
    scanf("%s",team2);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %c %d %c",&Card[i].m,&Card[i].ha,&Card[i].pn,&Card[i].ry);
    qsort(Card,n,sizeof(node),cmp);
    for(int i=0;i<n;i++) {
        if(Card[i].ha=='h') {
            if(Card[i].ry=='r' &&play1[Card[i].pn]!=2) {
                printf("%s %d %d\n",team1,Card[i].pn,Card[i].m);
                play1[Card[i].pn]=2;
            } else if(Card[i].ry=='y'&&play1[Card[i].pn]!=2) {
                play1[Card[i].pn]++;
                if(play1[Card[i].pn]==2)    printf("%s %d %d\n",team1,Card[i].pn,Card[i].m);
            }
        } else {
            if(Card[i].ry=='r' &&play2[Card[i].pn]!=2) {
                printf("%s %d %d\n",team2,Card[i].pn,Card[i].m);
                play2[Card[i].pn]=2;
            } else if(Card[i].ry=='y'&&play2[Card[i].pn]!=2) {
                play2[Card[i].pn]++;
                if(play2[Card[i].pn]==2)    printf("%s %d %d\n",team2,Card[i].pn,Card[i].m);
            }
        }
    }


    return 0;
}
