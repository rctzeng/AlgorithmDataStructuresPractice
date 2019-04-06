#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 101

typedef struct rwall{
    int L, y;
}rwall;

int Map[MAX][MAX];
rwall toRemove[MAX];

int cmp(const void *a,const void *b){
    rwall c = *(rwall *)a;
    rwall d = *(rwall *)b;
    return d.L-c.L;
}

int main(){
    int t;
    scanf("%d",&t);
    int n,k,i,j,l,c,a,b,xl,xr,yl,yr;
    while(t--){
        scanf("%d%d",&n,&k);
        memset(Map,0,sizeof(Map));
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
            if(xl>xr){
                    j=xl;xl=xr;xr=j;
            }
            for(j=xl;j<=xr;j++) Map[j][yl]=xr-j+1;
        }

        for(c=0,i=0;i<MAX;i++){
            for(l=0,j=0;j<MAX;j++)
                if(Map[i][j]!=0){
                    toRemove[l].y=j;
                    toRemove[l++].L=Map[i][j];
                }

            if(l>k){
                qsort(toRemove,l,sizeof(rwall),cmp);
                for(j=0;j<l-k;j++){
                    c++;b=Map[i][toRemove[j].y];
                    for(a=i;a<i+b;a++)
                        Map[a][toRemove[j].y]=0;
                }
            }
        }
        printf("%d\n",c);
    }

    return 0;
}
