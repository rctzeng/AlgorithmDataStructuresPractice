#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max(x,y) (x)>(y)?(x):(y)
#define MAX 1001

int LCS[MAX][MAX];
char WN[MAX][21],TN[MAX][21],T[MAX],W[MAX];


int main(){
    int nT,i,j,lw,lt,w,t,sw,st,f;
    nT=0;
    while(gets(W)!=NULL){
        gets(T);
        w=strlen(W);t=strlen(T);
        if(!w||!t){
            printf("%2d. Blank!\n",++nT);
            continue;
        }
        lw=1;lt=1;sw=0;st=0;f=0;
        for(i=0;i<w;i++){
            if(isalpha(W[i])||isdigit(W[i]))
               WN[lw][sw++]=W[i],f=1;
            else if(f){
                WN[lw++][sw]='\0';
                sw=0;f=0;
            }
        }
        if(f)
            WN[lw++][sw]='\0';

        for(f=0,i=0;i<t;i++){
            if(isalpha(T[i])||isdigit(T[i]))
               TN[lt][st++]=T[i],f=1;
            else if(f){
                TN[lt++][st]='\0';
                st=0;f=0;
            }
        }
        if(f)
            TN[lt++][st]='\0';

        memset(LCS,0,sizeof(LCS));
        for(i=1;i<lw;i++)
            for(j=1;j<lt;j++){
                if(strcmp(WN[i],TN[j])==0)
                    LCS[i][j]=max(LCS[i-1][j-1]+1,LCS[i][j]);
                else    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }

        printf("%2d. Length of longest match: %d\n",++nT,LCS[lw-1][lt-1]);
    }
    return 0;
}
