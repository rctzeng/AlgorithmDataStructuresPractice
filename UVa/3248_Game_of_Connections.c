#include<stdio.h>

#define MAX 101
#define max(x,y) (x)>(y)?(x):(y)

int Num[MAX][MAX];
int length[MAX],l;

int* Mul(int a, int b);
void Add(int *a, int result);

int main(){
    int N,i,j;
    Num[0][0]=1;length[0]=1;
    for(i=1;i<MAX;i++)
        for(j=0;j<i;j++)
            Add(Mul(j,i-j-1),i);

    while(scanf("%d",&N)&&(N>0)){
        for(i=length[N]-1;i>=0;i--)
            printf("%d",Num[N][i]);
        printf("\n");
    }

    return 0;
}

int* Mul(int a, int b){
    int i,j,ca,t,m;
    int c[MAX];
    memset(c,0,sizeof(c));
    ca=0;m=0;
    for(i=0;i<length[a];i++){
        for(j=0;j<length[b];j++){
            t=c[i+j]+ca+Num[a][i]*Num[b][j];
            c[i+j]=t%10;
            ca=t/10;
        }
        if(ca)  c[i+j]+=ca;
        ca=0;
    }

    if(ca)  c[i+j-1]+=ca,m=max(m,i+j);
    else    m=max(m,i+j-1);
    ca=0;
    l=m;
    return c;
}
void Add(int *a, int result){
    int i,lm,c,t;
    lm=max(l,length[result]);
    c=0;
    for(i=0;i<lm;i++){
        t=Num[result][i]+c+a[i];
        Num[result][i]=t%10;
        c=t/10;
    }
    if(c)   length[result]=lm+1,Num[result][lm]=c;
    else    length[result]=lm;
}
