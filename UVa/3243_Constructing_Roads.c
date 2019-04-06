#include<stdio.h>
#include<stdlib.h>

#define MAX 5001

typedef struct Edge{
   int a,b,d;
}Edge;

int Parent[101];
Edge E[MAX];

int Find_in(int a);
int Union(int a,int b);
int cmp(const void *a, const void *b){
    return (*(Edge *)a).d-(*(Edge *)b).d;
}

int main(){
    int N,Q,i,j,n,a,b,ans;
    while(scanf("%d",&N)!=EOF){
        n=0;
        for(i=0;i<N;i++){
            Parent[i]=i;
            for(j=0;j<N;j++){
                scanf("%d",&E[n].d);
                if(i!=j&&i<j){
                    E[n].a=j;E[n++].b=i;
                }
            }
        }
        scanf("%d",&Q);
        for(i=0;i<Q;i++){
            scanf("%d%d",&a,&b);
            if(Find_in(a-1)!=Find_in(b-1))
                Union(a-1,b-1);
        }
        ans=0;
        qsort(E,n,sizeof(Edge),cmp);
        for(i=0;i<n;i++){
            if(Find_in(E[i].a)!=Find_in(E[i].b)){
                Union(E[i].a,E[i].b);
                ans+=E[i].d;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}

int Find_in(int a){
    return a==Parent[a]?a:Find_in(Parent[a]);
}
int Union(int a,int b){
    Parent[Find_in(a)]=b;
}
