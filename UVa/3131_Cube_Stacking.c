#include<stdio.h>
#include<string.h>

#define MAX 30001

int Set[MAX], Len[MAX], Top[MAX];//Set[i]為元素i所在的stack底, Top[i]為元素i所在的stack頂

void join_Set(int a,int b);
int find_Set(int p);

int main(){
    int i;
    for(i=1;i<MAX;i++)  Top[i]=i;
    memset(Set,-1,sizeof(Set));
    memset(Len,0,sizeof(Len));

    int P;
    scanf("%d", &P);

    char act[2];
    int a, b;
    while(P--){
        scanf("%s", act);
        if(act[0]=='M'){
            scanf("%d%d",&a,&b);
            join_Set(a,b);
        }else{
            scanf("%d",&a);
            find_Set(a);
            printf("%d\n",Len[a]);
        }
    }

    return 0;
}

void join_Set(int a,int b){
    int as,bs;
    as=find_Set(a);
    bs=find_Set(b);
    if(as!=bs){
        Set[as]=bs;
        Len[as]+=Len[Top[bs]]+1;
        find_Set(Top[as]);
        Top[bs]=Top[as];
    }
    return;
}
int find_Set(int p){
    if(Set[p]<0)   return p;
    if(Set[Set[p]]>=0){
        int a=Set[p];
        Set[p]=find_Set(a);
        Len[p]+=Len[a];
    }

    return Set[p];
}
