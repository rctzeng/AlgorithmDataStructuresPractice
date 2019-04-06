#include<stdio.h>
#include<string.h>

#define MAX 1000001
#define max(x,y) (x)>(y)?(x):(y)

char s[MAX];
int suf[MAX];

int main(){
    int i,p,l,pl,n;
    while(scanf("%s",s)!=EOF && s[0]!='.'){
        suf[0]=-1;suf[1]=0;pl=0;
        p=0;l=strlen(s);
        for(i=2;i<=l;i++){
            while(p>=0 && s[p]!=s[i-1]) p=suf[p];
            suf[i]=++p;
            if(!(l%(i-suf[i])))
                pl=max(pl,i-suf[i]);
        }

        i=0;p=0;n=0;
        while(i<l){
            if(s[i]==s[p])
                i++,p++;
            else
                break;
            if(p==pl)
                p=0,n++;
        }

        if(n==l/pl) printf("%d\n",n);
        else    printf("1\n");
    }

    return 0;
}
