#include<stdio.h>
#include<string.h>

#define MAX 100001

char str[MAX];
int Q[MAX];

int main(){
    char c;
    long long int r,d,i;
    int l;
    while(scanf("%s %c %lld",str,&c,&d)!=EOF){
        memset(Q,0,sizeof(Q));
        r=0;l=strlen(str);
        for(i=0;i<l;i++){
            r=r*10+(str[i]-'0');
            Q[i]=r/d;
            r%=d;
        }

        if(c=='%')
            printf("%lld\n",r);
        if(c=='/'){
            for(i=0;i<l;i++)
                if(Q[i])    break;

            if(Q[i]==0) printf("0");
            for(;i<l;i++)
                printf("%d",Q[i]);
            printf("\n");
        }
    }
}
