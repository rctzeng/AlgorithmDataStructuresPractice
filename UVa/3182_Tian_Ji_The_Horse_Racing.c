#include<stdio.h>
#include<stdlib.h>

#define MAX 1001

int King[MAX],Tian[MAX];

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    int n,i,sK,eK,sT,eT,c;

    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++)    scanf("%d",&Tian[i]);qsort(Tian,n,sizeof(int),cmp);
        for(i=0;i<n;i++)    scanf("%d",&King[i]);qsort(King,n,sizeof(int),cmp);

        sK=sT=0;eK=eT=n-1;c=0;
        while(n--){
            if(Tian[sT]>King[sK]){
                sK++;c++;sT++;
            }else if(Tian[sT]<King[sK]){
                if(Tian[sT]<King[eK])
                    c--;
                eK--;sT++;
            }else{
                if(Tian[eT]>King[eK]){
                    eK--;eT--;c++;
                }else{
                    if(Tian[sT]<King[eK])
                        c--;
                    sT++;eK--;
                }
            }
        }

        printf("%d\n",c*200);
    }

    return 0;
}
