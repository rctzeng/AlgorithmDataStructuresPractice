#include<stdio.h>
#include<string.h>

int main(){
    int t,i,l,f1,f0;
    char str[21];
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        l=strlen(str);
        f1=f0=0;
        for(i=0;i<l;i++){
            if(str[i]=='1') f1=1;
            else    f0=1;
        }
        if(f1&&f0)  printf("2\n");
        else    printf("1\n");
    }

    return 0;
}
