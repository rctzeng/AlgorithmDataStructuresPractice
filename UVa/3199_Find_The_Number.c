#include<stdio.h>
#include<string.h>

long long int dep[12],id[12];

int main(){
    int t;
    scanf("%d",&t);
    int k,n,i,j,it,num,d;
    long long int tt;
    for(it=0;it<t;it++){
        scanf("%d%d",&k,&n);
        tt=-1;num=0;
        for(i=0;i<k;i++){
            scanf("%lld",&dep[i]);
            id[i]=0;
        }
        tt=0;
        while(num<n){
            for(i=0;i<k;i++){
                while(1){
                    if(dep[i]*id[i]>tt){
                        d=1;
                        for(j=0;j<k;j++){
                            if(i!=j && !((dep[i]*id[i])%dep[j])){
                                d=0;id[i]++;
                                break;
                            }
                        }
                        if(d)   break;
                    }else
                        id[i]++;
                }
            }

            for(i=0;i<k;i++){
                if(i){
                    if(tt>dep[i]*id[i])
                        tt=dep[i]*id[i];
                }else   tt=dep[i]*id[i];
            }
            num++;
        }

        printf("%lld\n",tt);
    }

    return 0;
}
