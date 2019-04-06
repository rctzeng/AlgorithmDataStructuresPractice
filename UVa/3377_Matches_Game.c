#include<stdio.h>

int main(){
    int n,a,i,t;
    while(scanf("%d",&n)!=EOF){
        for(i=a=0;i<n;i++){
            scanf("%d",&t);
            a=a^t;
        }

        if(a)   printf("Yes\n");
        else    printf("No\n");
    }
}
