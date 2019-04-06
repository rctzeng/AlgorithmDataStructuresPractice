#include<stdio.h>
#include<string.h>

#define MAX 2000

int N[MAX][2],k,n,F; /*[0] for s, [1] for e*/
int din[MAX],dout[MAX];
int visit[MAX],ans[MAX];

void DFS(int a);

int main(){
    int a,b,w,i;
    while(scanf("%d%d",&a,&b)==2&&(a+b)){
        n=0;
        scanf("%d",&w);
        n++;
        N[w][0]=a;N[w][1]=b;
        while(scanf("%d%d",&a,&b)==2&&(a+b)){
            scanf("%d",&w);
            N[w][0]=a;N[w][1]=b;
            n++;
        }
        memset(visit,0,sizeof(visit));
        memset(din,0,sizeof(din));
        memset(dout,0,sizeof(dout));
        memset(ans,0,sizeof(ans));
        k=0;visit[1]=1;din[N[1][0]]++;dout[N[1][1]]++;ans[k++]=1;F=0;
        DFS(1);
        if(F==1){
            for(i=0;i<n;i++){
                if(i)   printf(" ");
                printf("%d",ans[i]);
            }
            printf("\n\n");
        }else   printf("Round trip does not exit.\n\n");
    }

    return 0;
}

void DFS(int a){
    printf("a=%d\n",a);
    int i,f;
    if(k==n){
        f=1;
        for(i=1;i<=n;i++)
            if(!visit[i]||din[i]!=dout[i])
                f=0;
        if(f){
            F=1;return;
        }
    }

    for(i=1;i<=n;i++){
        if(!visit[i]&&N[i][0]==N[a][1]){
            printf("a=%d, ea=%d, i=%d, si=%d\n",a,N[a][1],i,N[i][0]);
            din[N[i][0]]++;dout[N[i][1]]++;
            visit[i]=1;ans[k++]=i;
            DFS(i);
            k--;
        }
    }
}
