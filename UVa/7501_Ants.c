#include<stdio.h>
#include<stdlib.h>

#define MAX 10001
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    int L,n,t,i,mi,ma,tmi,se;
    int Ant[MAX];
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&L,&n);
        for(i=0;i<n;i++)    scanf("%d",&Ant[i]);
        qsort(Ant,n,sizeof(int),cmp);
        mi=ma=0;
        for(i=0;i<n;i++){
            mi=max(mi,min(Ant[i],L-Ant[i]));
            if(i==0)    se=Ant[i];
            if(i==n-1)  se=max(se,L-Ant[i]);
            else    ma+=Ant[i+1]-Ant[i];
        }ma+=se;

        printf("%d %d\n",mi,ma);
    }

    return 0;
}
