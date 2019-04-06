#include<stdio.h>
#include<string.h>

#define min(x,y) (x)<(y)?(x):(y)

int main(){
    int i,j;
    long long int a,b,ans;
    while(scanf("%lld%lld",&a,&b)==2&&(a+b)){
        printf("%lld things taken %lld at a time is ",a,b);
        b=min(b,a-b);
        if(b==1)    printf("%lld exactly.\n",a);
        else if(b==0)   printf("1 exactly.\n");
        else{
            ans=1;
            for(i=1,j=a;i<=b;i++,j--){
                ans*=j;
                ans/=i;
            }
            printf("%lld exactly.\n",ans);
        }
    }

    return 0;
}
