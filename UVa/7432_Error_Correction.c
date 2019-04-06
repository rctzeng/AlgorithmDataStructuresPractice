#include<stdio.h>
#include<string.h>

int Matrix[101][101];
int Rs[101],Cs[101];

int main(){
    int n,i,j,t,r,w,a,b;
    while(scanf("%d",&n)&&n){
        memset(Rs,0,sizeof(Rs));
        memset(Cs,0,sizeof(Cs));
        r=0;w=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&Matrix[i][j]);
                Rs[i]=(Rs[i]+Matrix[i][j])%2;
                Cs[j]=(Cs[j]+Matrix[i][j])%2;
            }
            if(Rs[i])   r++,a=i;
        }
        for(i=0;i<n;i++)    if(Cs[i])   w++,b=i;
        if(!r&&!w)  printf("OK\n");
        else if(r==1&&w==1) printf("Change bit (%d,%d)\n",a+1,b+1);
        else    printf("Corrupt\n");
    }

    return 0;
}
