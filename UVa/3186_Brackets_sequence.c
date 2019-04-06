#include<stdio.h>
#include<string.h>

#define MAX 110

char Bracket[MAX];
int dp[MAX][MAX],path[MAX][MAX];

void print(int i,int j);

int main(){
    int t,T,i,j,k,bl,l;
    scanf("%d\n",&T);
    for(t=1;t<=T;t++){
        gets(Bracket);
        if(t!=1)    printf("\n");
        if(Bracket[0]!='\0'){
            bl=strlen(Bracket);
            memset(dp,0,sizeof(dp));
            for(i=0;i<bl;i++)   dp[i][i]=1;

            for(l=1;l<=bl;l++)
                for(i=0;i<bl;i++){
                    j=i+l;
                    if(j==bl)   break;
                    if((Bracket[i]=='('&&Bracket[j]==')')||(Bracket[i]=='['&&Bracket[j]==']')){
                        path[i][j]=-1;
                        dp[i][j]=dp[i+1][j-1];
                    }else
                        dp[i][j]=MAX;

                    for(k=i;k<j;k++)
                        if(dp[i][k]+dp[k+1][j]<dp[i][j]){
                            dp[i][j]=dp[i][k]+dp[k+1][j];
                            path[i][j]=k;
                        }
                }
                print(0,bl-1);
            }

        printf("\n");
        if(t!=T)
            getchar();
    }

    return 0;
}

void print(int i,int j){
    if(i==j){
        if(Bracket[i]=='('||Bracket[i]==')')
            printf("()");
        else    printf("[]");
    }else if(path[i][j]==-1){
        printf("%c",Bracket[i]);
        if(i+1!=j)
            print(i+1,j-1);
        printf("%c",Bracket[j]);
    }else{
        print(i,path[i][j]);
        print(path[i][j]+1,j);
    }
}
