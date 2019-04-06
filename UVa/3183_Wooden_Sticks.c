#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5001

typedef struct Wood{
    int l,w;
}Wood;

Wood wood[MAX];
int used[MAX];

int cmp(const void *a,const void *b){
    Wood c=*(Wood *)a;
    Wood d=*(Wood *)b;
    if(c.l!=d.l) return c.l-d.l;
    else return c.w-d.w;
}

int main(){
    int t,n,c,i,j,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&wood[i].l,&wood[i].w);

        qsort(wood,n,sizeof(Wood),cmp);
        memset(used,0,sizeof(used));

        for(c=0,i=0;i<n;i++){
            if(!used[i]){
                c++;used[i]=1;w=wood[i].w;
                for(j=i+1;j<n;j++){
					if(!used[j]&&w<=wood[j].w){
                        used[j]=1;w=wood[j].w;
					}
                }
            }
        }

        printf("%d\n",c);
    }

    return 0;
}
