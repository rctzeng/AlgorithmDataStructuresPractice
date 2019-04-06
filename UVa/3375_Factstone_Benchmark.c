#include<stdio.h>
#include<math.h>

#define Max 300001

double factLog[Max];

int main(){
    int i,n;
    factLog[0]=factLog[1]=0.0;
    for(i=2;i<Max;i++)
        factLog[i]=factLog[i-1]+log((double)i);

    while(scanf("%d",&n)!=EOF &&n){
        for(i=0;i<Max;i++)
            if(factLog[i]-log(2.0)*(1<<(n/10-194))>0.0)
                break;
        printf("%d\n",i-1);
    }

    return 0;
}
