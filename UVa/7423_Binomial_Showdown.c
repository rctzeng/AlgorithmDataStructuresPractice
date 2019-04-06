#include<stdio.h>
#include<string.h>

#define min(x,y) (x)<(y)?(x):(y)

int main(){
    int i,j;
    long long int a,b,ans;
    while(scanf("%lld%lld",&a,&b)==2&&(a+b)){
        b=min(b,a-b);
        if(b==1)    printf("%lld\n",a);
        else if(b==0)   printf("1\n");
        else{
            ans=1;
            for(i=1,j=a;i<=b;i++,j--){
                ans*=j;
                ans/=i;
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}
