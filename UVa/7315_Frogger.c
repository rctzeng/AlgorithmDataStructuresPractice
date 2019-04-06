#include<stdio.h>
#include<math.h>
#define max(x,y) (x)>(y)?(x):(y)

typedef struct Edge{
   int a,b,d;
}Edge;

Edge E[40001];
int Coor[201][2],Parent[201];

int Find_in(int a);
int Union(int a,int b);
int cmp(const void *a, const void *b){
    return (*(Edge *)a).d-(*(Edge *)b).d;
}

int main(){
    int N,T,i,j,n,ans;
    T=0;
    while(scanf("%d",&N)!=EOF&&N){
        for(i=0;i<N;i++)    scanf("%d%d",&Coor[i][0],&Coor[i][1]),Parent[i]=i;
        n=0;
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++){
                E[n].d=(Coor[i][0]-Coor[j][0])*(Coor[i][0]-Coor[j][0])+(Coor[i][1]-Coor[j][1])*(Coor[i][1]-Coor[j][1]);
                E[n].a=i;E[n].b=j;n++;
            }

        ans=0;
        qsort(E,n,sizeof(Edge),cmp);
        for(i=0;i<n;i++){
            if(Find_in(0)==Find_in(1))  break;
            if(Find_in(E[i].a)!=Find_in(E[i].b)){
                Union(E[i].a,E[i].b);
                ans=max(ans,E[i].d);
            }
        }

        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++T,sqrt(ans));
    }

    return 0;
}

int Find_in(int a){
    return a==Parent[a]?a:Find_in(Parent[a]);
}
int Union(int a,int b){
    Parent[Find_in(a)]=b;
}
