#include<stdio.h>
#include<string.h>

#define MAX 201

int main(){
    int t,i,C,msb,la,lb,l;
    char a[MAX],b[MAX],c[MAX];
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",a,b);
        C=0;la=strlen(a);lb=strlen(b);
        if(la>lb)   l=la;
        else    l=lb;
        for(i=0;i<=l;i++){
            if(i>=la)   a[i]='0';
            if(i>=lb)   b[i]='0';
            c[i]=(C+a[i]+b[i]-'0'*2)%10;
            C=(C+a[i]+b[i]-'0'*2)/10;
            if(c[i])    msb=i;
        }
        for(i=0;i<=msb;i++)
            if(c[i])    break;
        for(;i<=msb;i++)
            printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}
