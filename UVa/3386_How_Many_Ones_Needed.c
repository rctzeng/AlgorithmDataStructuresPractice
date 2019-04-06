#include<stdio.h>

#define MAX (1<<16)

long long int pre[MAX],one[MAX];

int main(){
    int i,p1,p2,d1,d2;
    long long int a,b,ap,bp,mp,ab;
    pre[0]=0;one[0]=0;
    for(i=1;i<MAX;i++){
        one[i]=one[i/2]+i%2;
        pre[i]=pre[i-1]+one[i];
    }

    int C=0;
    while(scanf("%lld%lld",&a,&b)!=EOF&&(a+b)){
        p1=a%MAX;
        p2=a/MAX;
        d1=b%MAX;
        d2=b/MAX;
        ap=(pre[MAX-1]-pre[p1]+one[p1])+(MAX-p1)*one[p2];
        bp=pre[d1]+(d1+1)*one[d2];
        mp=(pre[d2]-pre[p2]-one[d2])*MAX+pre[MAX-1]*(d2-p2-1);
        printf("Case %d: %lld\n",++C,ap+bp+mp);
    }

    return 0;
}
