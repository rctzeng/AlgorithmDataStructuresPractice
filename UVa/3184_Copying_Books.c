#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)
#define MAX 501

int Book[MAX],m,k;
int apart[MAX],f[MAX];

int check(long long int up_b);

int main(){
    int t,i;
    long long int r,l,mid,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&k);
        for(sum=0,i=0;i<m;i++){
            scanf("%d",&Book[i]);
            sum+=Book[i];
        }

        l=0;r=sum;
        for(i=0;i<m;i++)
            l=max(l,Book[i]);

        while(l!=r){
            mid=(l+r)/2;
            if(check(mid)==1)
                r=mid;
            else
                l=mid+1;
        }
        check(l);

        for(i=0;i<m;i++){
            printf("%d",Book[i]);
            if(i<m-1) printf(" ");
            if(f[i])    printf("/ ");
        }
        printf("\n");
    }

    return 0;
}

int check(long long int up_b){
    memset(f,0,sizeof(f));
    long long int now=0;
    int i,scribN;
    scribN=k;
    for(i=m-1;i>=0;i--){
        if(now+Book[i]>up_b||i<scribN-1){
            now=Book[i];
            scribN--;
            f[i]=1;
            if(scribN==0)   return -1;
        }
        else    now+=Book[i];
    }
    return 1;
}
