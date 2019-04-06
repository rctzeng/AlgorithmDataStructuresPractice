#include <stdio.h>

#define MAX 200001

int A[MAX];
int B[MAX];

int main() {
    int n;
    scanf("%d",&n);
    int t;
    int la,lb;
    la=lb=0;
    int last=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&t);
        if(t>0) A[la++]=t;
        else    B[lb++]=-t;
        if(i==n-1)  last=t;
    }
    long long int sa,sb;
    sa=sb=0;
    for(int i=0;i<la;i++)   sa+=A[i];
    for(int i=0;i<lb;i++)   sb+=B[i];
    if(sa>sb)   printf("first\n");
    else if(sa<sb)  printf("second\n");
    else {
        int flag=0;
        for(int i=0;i<la&&i<lb&&flag==0;i++) {
            if(A[i]>B[i])   flag=1;
            else if(A[i]<B[i])  flag=-1;
        }
        if(flag==0) {
            if(la>lb)   flag=1;
            else if(la>lb)  flag=-1;
        }

        if(flag==0) {
            if(last>0)  flag=1;
            else    flag=-1;
        }

        if(flag==1) printf("first\n");
        else if(flag==-1)   printf("second\n");
    }

    return 0;
}
