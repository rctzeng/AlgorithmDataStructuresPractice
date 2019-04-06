#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)
#define MAX 200

int Exp[MAX],Ans[MAX],temp[MAX];

int main(){
    int i,p,n,j,ni,l,ml,mil;
    char str[10];
    while(scanf("%s %d",str,&n)!=EOF){
        memset(Ans,0,sizeof(Ans));
        for(i=0,j=4;i<=5;i++){
            if(str[i]!='.')
                Exp[j--]=str[i]-'0';
            else    p=5-i;
        }

        l=1;Ans[0]=1;mil=-1;
        for(ni=0;ni<n;ni++){
            memset(temp,0,sizeof(temp));
            for(i=0;i<5;i++)
                for(j=0;j<l;j++)
                    temp[i+j]+=Exp[i]*Ans[j];
            l+=5;
            for(i=0;i<l;i++){
                if(temp[i]>9){
                    temp[i+1]+=temp[i]/10;
                    temp[i]%=10;
                }Ans[i]=temp[i];
                if(ni==n-1&&Ans[i]){
                    ml=i;
                    if(mil==-1) mil=i;
                }
            }
        }

        for(i=max(ml,n*p-1);i>=mil;i--){
            if(i==n*p-1)  printf(".");
            printf("%d",Ans[i]);
        }
        printf("\n");
    }

    return 0;
}
