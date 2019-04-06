#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int A[5],M,ans,sum,fs,fm;
    for(int i=1;i<=T;i++){
        sum=0;
        for(int j=0;j<5;j++){
            scanf("%d",&A[j]);
            sum+=A[j];
        }
        scanf("%d",&M);
        if(M>0){
            if(sum>0)
                for(ans=0;(sum<<ans)<M;ans++);
            else    ans=-1;
        }
        else if(M<0){
            if(sum>M)   ans=0;
            else    ans=-1;
        }
        else{
            if(sum>=0)  ans=0;
            else    ans=-1;
        }

        printf("Case #%d: %d\n",i,ans);
    }

    return 0;
}
