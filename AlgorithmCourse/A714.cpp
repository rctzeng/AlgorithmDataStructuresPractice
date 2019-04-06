#include <stdio.h>
#include <string.h>

#define MAX 501

int Book[MAX];
int Cut[MAX];
int k,m;

int compute(long long int n);

int main() {
    //freopen("out.txt","w+",stdout);
    int N;
    scanf("%d",&N);
    while(N--) {
        long long int sum=0;
        scanf("%d%d",&k,&m);
        for(int i=0;i<k;i++) {
            scanf("%d",&Book[i]);
            sum+=Book[i];
        }

        long long int l=0, r=sum;

        long long int bm;
        while(l<r) {
            bm=(l+r)/2;
            if(compute(bm)==1)
                r=bm;
            else   l=bm+1;
        }
        compute(l);

        for(int i=0;i<k;i++) {
            printf("%d",Book[i]);
            if(i!=k-1)  printf(" ");
            if(Cut[i])  printf("/ ");
        }
        if(N)   printf("\n");
    }

    return 0;
}

int compute(long long int n) {
    long long int t=0;
    int c=m-1;
    memset(Cut,0,sizeof(Cut));
    for(int i=k-1;i>=0;i--) {
        if (t+Book[i]>n || i<c) {
            Cut[i]=1;
            t=Book[i];
            c--;
        } else
            t+=Book[i];
        if(c<0)    return 0;
    }
    return 1;
}
