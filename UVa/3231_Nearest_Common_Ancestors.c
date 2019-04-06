#include<stdio.h>

#define MAX 10001

int parent[MAX];
int d[MAX],com,m;

void find_p(int a,int b);

int main(){
    int T,N,i,c,p;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=1;i<=N;i++)    parent[i]=-1;
        for(i=1;i<N;i++){
            scanf("%d%d",&p,&c);
            parent[c]=p;
        }
        scanf("%d%d",&p,&c);
        d[p]=d[c]=0;m=MAX;
        find_p(p,c);
        printf("%d\n",com);
    }

    return 0;
}

void find_p(int a,int b){
    if(a!=-1&&b!=-1){
        if(a==b&&d[a]<m){
            com=a;
            m=d[a];
        }else{
            d[parent[a]]=d[a]+1;
            if(d[parent[a]]<m)
                find_p(parent[a],b);
            d[parent[b]]=d[b]+1;
            if(d[parent[b]]<m)
                find_p(a,parent[b]);
        }
    }else   return;
}
