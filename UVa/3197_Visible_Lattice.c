#include<stdio.h>

#define MAX 101

int Vis[MAX];
int gcd(int a,int b);

int main(){
    int t,n,i,j,k;
    for(n=1;n<MAX;n++){
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                for(k=0;k<=n;k++){
                    if(i==0){
                        if(j==0&&k&&k==1) Vis[n]++;
                        else if(j&&k&&gcd(j,k)==1)  Vis[n]++;
                        else if(j&&k==0&&j==1)   Vis[n]++;
                    }else{
                        if(j&&k&&gcd(i,gcd(j,k))==1)   Vis[n]++;
                        else if(j==0&&k&&gcd(i,k)==1)   Vis[n]++;
                        else if(k==0&&j&&gcd(j,i)==1)   Vis[n]++;
                        else if(j==0&&k==0&&i==1)  Vis[n]++;
                    }
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
