#include<stdio.h>

#define MAX 101

int Vis[MAX];
int gcd(int a,int b);

int main(){
    int t,n,i,j,k;
    Vis[1]=7;
    for(n=2;n<MAX;n++){
        Vis[n]=Vis[n-1];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==0&&j&&gcd(n,j)==1)   Vis[n]+=3;
                else if(i&&j==0&&gcd(n,i)==1)   Vis[n]+=3;
                else if(i&&j&&gcd(j,gcd(i,n))==1)   Vis[n]+=3;
            }
            if(gcd(i,n)==1) Vis[n]+=3;
        }
    }

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",Vis[n]);
    }

    return 0;
}

int gcd(int a,int b){
    while((a%=b)&&(b%=a));
    return a+b;
}
