#include<stdio.h>
#include<stdlib.h>

#define MAX 1000001
#define max(x,y) (x)>(y)?(x):(y)
    
typedef struct node{
    long long int n1,n2; long long int num;
} node;

node AB[MAX], CD[MAX]; //a+b, c-d
int find; long long int ans;

int cmp(const void *a, const void *b) { return (*(node *)a).num-(*(node *)b).num;}
void check(int ab1, int ab2, int cd1, int cd2) {
    int i,j;
    for(i=ab1;i<=ab2;i++)
        for(j=cd1;j<=cd2;j++)
            if((AB[i].n1!=CD[j].n1)&&(AB[i].n1!=CD[j].n2)&&(AB[i].n2!=CD[j].n1)&&(AB[i].n2!=CD[j].n2)) {
                ans=(find)?(max(ans,CD[j].n1)):(CD[j].n1); find=1;
            }
}

int main() {
    int N,i,j,lab,lcd;
    long long int num[1001];
    while(scanf("%d", &N)==1) {
        if(N==0) break;
        for (i=0;i<N;i++) scanf("%lld",&num[i]);
        // compute A+B, C-D --> O(N^2)
        lab=lcd=0;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++) {
                if (num[i]==num[j]) continue;
                AB[lab].n1=num[i]; AB[lab].n2=num[j]; AB[lab].num=num[i]+num[j]; lab++;
                CD[lcd].n1=num[i]; CD[lcd].n2=num[j]; CD[lcd].num=num[i]-num[j]; lcd++;
            }
        // sort --> O(N^2 ln N^2)
        qsort(AB, lab, sizeof(node), cmp);
        qsort(CD, lcd, sizeof(node), cmp);
        // merge --> O(N^2+n^2), worst case n=N^2
        int ab1,ab2,cd1,cd2,in,prev; find=in=i=j=0;
        while((i<lab) && (j<lcd)) {
            if(AB[i].num<CD[j].num) {
                if(in==1) {in=0; check(ab1,ab2,cd1,cd2);}
                i++;
            } else if(AB[i].num>CD[j].num) {
                if(in==1) {in=0; check(ab1,ab2,cd1,cd2);}
                j++;
            } else {
                if(in==0) {in=1; ab1=ab2=i; cd1=cd2=j; prev=AB[i].num;}
                else if (in==1 && prev==AB[i].num) {ab2=max(ab2,i); cd2=max(cd2,j);}
                else {check(ab1,ab2,cd1,cd2); ab1=ab2=i; cd1=cd2=j; prev=AB[i].num;}
                i++; j++;
            }
        }
        if(in==1) {in=0; check(ab1,ab2,cd1,cd2);}
        
        if(find) printf("%lld\n", ans);
        else printf("no solution\n");
    }
    
    return 0;
}
