#include<stdio.h>

#define MAX 1000001

char str[MAX];
int pre[MAX];

int main(){
    int t=0;
    int n,i,p;
    while(scanf("%d",&n)!=EOF && n){
        scanf("%s",str);
        printf("Test case #%d\n",++t);

        pre[0]=p=-1;
        for(i=1;i<n;i++){
            while(p>=0 && str[p+1]!=str[i]) p=pre[p];
            if(str[p+1]==str[i])    p++;
            pre[i]=p;
            if(p>=0 &&!((i+1)%(i-p)))
                printf("%d %d\n",i+1,(i+1)/(i-p));
        }
        printf("\n");
    }

    return 0;
}
