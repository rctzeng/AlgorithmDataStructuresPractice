#include<stdio.h>
#include<string.h>

#define MAX 400001

char str[MAX];
int suf[MAX],N[MAX];

int main(){
    int i,l,p,n;
    while(scanf("%s",str)!=EOF){
        l=strlen(str);
        suf[0]=p=-1;
        for(i=1;i<l;i++){
            while(p>=0 && str[p+1]!=str[i]) p=suf[p];
            if(str[p+1]==str[i])    p++;
            suf[i]=p;
        }

        p=l-1;n=0;
        while(p>=0){
            N[n++]=p;
            p=suf[p];
        }

        for(i=n-1;i>=0;i--){
            printf("%d",N[i]+1);
            if(i)   printf(" ");
            else    printf("\n");
        }
    }

    return 0;
}
