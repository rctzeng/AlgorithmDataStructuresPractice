#include<stdio.h>
#include<stdlib.h>

#define MAX 1001

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    int t,i,b2,fplusl2;
    scanf("%d",&t);
    int n,P[MAX],s,e,p,time;
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)    scanf("%d",&P[i]);
        qsort(P,n,sizeof(int),cmp);
        s=0,e=n-1;time=0;
        if(s==e)
            printf("%d\n%d\n",P[s],P[s]);
        else{
            while(s<e){
                fplusl2=P[s]+P[e-1];
                b2=P[s+1]*2;
                if(e>2){
                    if(b2>fplusl2)
                        time+=P[e]+P[s]+P[e-1]+P[s];
                    else
                        time+=P[s+1]+P[s]+P[e]+P[s+1];
                    e-=2;
                }else if(e==2){
                    time+=P[e]+P[s]+P[s+1];
                    e-=3;
                }else{
                    time+=P[e];
                    e-=2;
                }
            }

            printf("%d\n",time);

            s=0,e=n-1;
            while(s<e){
                fplusl2=P[s]+P[e-1];
                b2=P[s+1]*2;
                if(e>2){
                    if(b2>fplusl2)
                        printf("%d %d\n%d\n%d %d\n%d\n",P[s],P[e],P[s],P[s],P[e-1],P[s]);
                    else
                        printf("%d %d\n%d\n%d %d\n%d\n",P[s],P[s+1],P[s],P[e-1],P[e],P[s+1]);
                    e-=2;
                }else if(e==2){
                    printf("%d %d\n%d\n%d %d\n",P[s],P[e],P[s],P[s],P[s+1]);
                    e-=3;
                }else{
                    printf("%d %d\n",P[s],P[e]);
                    e-=2;
                }
            }
        }
        if(t)   printf("\n");
    }

    return 0;
}
