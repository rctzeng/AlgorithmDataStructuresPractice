#include<stdio.h>
#include<string.h>

#define MAX 100001

int set[MAX*2]; /* 共2*n個 前n個一個幫派 後n個另一個幫派 */

int find_set(int d);

int main(){
    int T;
    int i,a,b;
    char c[2];

    scanf("%d",&T);

    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        memset(set,-1,sizeof(set));
        for(i=0;i<m;i++){
            scanf("%s%d%d",c,&a,&b);
            if(c[0]=='A'){
                if(find_set(a)!=find_set(b) &&find_set(a)!=find_set(b+n))
                    printf("Not sure yet.\n");
                else if(find_set(a)==find_set(b))
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }else{
                if(find_set(a)!=find_set(b+n)){
                    set[find_set(a)]=find_set(b+n);
                    set[find_set(b)]=find_set(a+n);
                }
            }
        }
    }

    return 0;
}

int find_set(int d){
    if(set[d]<0)    return d;
    return set[d]=find_set(set[d]);
}
