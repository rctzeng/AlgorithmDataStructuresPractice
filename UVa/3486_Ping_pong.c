#include<stdio.h>

#define MAX 20001

typedef struct node{
    int num;
    int rank;
}node;

node A[MAX],temp[MAX];
int f1[MAX],f2[MAX],b1[MAX],b2[MAX];

void merge_sort(int p,int r);
void merge(int p,int q,int r);

int main(){
    int T,N,i;
    long long int ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%d",&A[i].rank);
            A[i].num=i;
        }

        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));

        merge_sort(0,N-1);

        ans=0;
        for(i=0;i<N;i++)
            ans+=f1[i]*b1[i]+f2[i]*b2[i];

        printf("%lld\n",ans);
    }

    return 0;
}

void merge_sort(int p,int r){
    if(p<r){
        int q=(p+r)>>1;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge(p,q,r);
    }
}
void merge(int p,int q,int r){
    int p1=p,p2=q+1,pa=0;
    /*
     f2[i], p1, f1[i], b1[i], p2, b2[i]
     (A[i], f1[i], b1[i]) or (f1[i], b1[i], A[i])
     , (f2[i], A[i], b2[i])
    */
    while(p1<=q && p2<=r){
        if(A[p1].rank < A[p2].rank){
            temp[pa].num=A[p1].num;
            temp[pa].rank=A[p1].rank;
            b2[A[p1].num]+=r-p2+1;
            b1[A[p1].num]+=p2-q-1;
            pa++,p1++;
        }else{
            temp[pa].num=A[p2].num;
            temp[pa].rank=A[p2].rank;
            f1[A[p2].num]+=q-p1+1;
            f2[A[p2].num]+=p1-p;
            pa++,p2++;
        }
    }
    while(p1<=q){
        temp[pa].num=A[p1].num;
        temp[pa].rank=A[p1].rank;
        b2[A[p1].num]+=r-p2+1;
        b1[A[p1].num]+=p2-q-1;
        pa++,p1++;
    }
    while(p2<=r){
        temp[pa].num=A[p2].num;
        temp[pa].rank=A[p2].rank;
        f1[A[p2].num]+=q-p1+1;
        f2[A[p2].num]+=p1-p;
        pa++,p2++;
    }

    int i;
    for(i=0;i<pa;i++){
        A[i+p].num=temp[i].num;
        A[i+p].rank=temp[i].rank;
    }
}
