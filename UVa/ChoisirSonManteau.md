# [France IOI 練習題 第4級的第4題](http://www.france-ioi.org/algo/task.php?idChapter=671&idTask=2330)

## 題目大意
給定 N 個溫度區間[l,r]，求一個溫度區間最多能包含（含端點）幾個其他的區間（不包括自己）？
0<N<=20000, 0<=l<=r<=500000000
Memory Limit: 8000KB, Time Limit: 0.5s

這題折磨了我超久~~~ 想法從基本排序到線段樹到線段樹優化 = = 最後終於過了(灑花)
後來過了看解答 發現這題存在天才聰明解!!!!!
我的解法:
先將 N 個區間, 照高溫(r)由小到大排序, 如果高溫相同, 在比較低溫(l), 大的排前面。 這麼做的原因是, 之後用低溫建segment Tree 時, 可以保證在這個高溫前的所有區間都已經看過了, 而且把低溫塞進segment Tree 時, 只要查找比這個低溫大的其他低溫個數, 就是目前這個溫度區間可以包含區間個數了。

天才解:
只要sort 兩次!!!
將所有溫度區間T[1,...,N]排序兩次:
一次照低溫小到大排(低溫同高溫大的優先)A[], 一次照高溫大到小排(高溫相同低溫小到大)B[]
如此, 考慮其中一個位置i, 對於A[i]來說排在它前面的不會被它包含, 同樣的排在B[i]之前的也不會被它包含
再回來, 考慮在原本溫度區間T中編號是i的溫度區間 T[i],
T[i]所能包含的最大區間數 == N(所有區間個數)-1(自己)-在A中排在它前面的個數-在B中排在它前面的個數
在這裡要特別注意的是可能會有區間T[j]包含T[i], 那麼T[j]在A和B中, 都會排在T[i]前面, 這樣算就會被扣兩次,
但是對於 包含最多其他區間的區間 來說一定是對的(不會有人包含它, 否則他就不是包含最多其他區間的區間)
```
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>

#define MAX 20001

using namespace std;

typedef struct T{
    int s,e; //s = 溫度低溫, e = 溫度高溫
}T;

typedef struct node{
    int thisN; //thisN 記錄有多少溫度區間在這一個區間內
    int lowB,upB; // 這個節點表示[lowB,upB]
}node;

T t[MAX];
node A[MAX*2]; //segmentTree 根結點編號1
int segIndex;

int cmp(const void *a, const void *b); //qsort 排序用
void build_segTree(int l, int r); // 初始化segmentTree 給每個節點決定區間範圍
int insert_segTree(int ins, int now);

int main(){
    int n;
    int i,ml,sn;
    map<int,int> Re; //jave 版本: Map<int, int> Re = new TreeMap<int, int>();
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d%d",&t[i].s,&t[i].e);
            Re[t[i].s]=1;=
        }

        //將所有點由小到大排重新編號: 1,...N, 離散化處理
        i=0;
        for(map<int,int>::iterator it=Re.begin();it!=Re.end();it++)
            it->second=++i;
        sn=i;
        qsort(t,n,sizeof(T),cmp);

        segIndex=0;
        build_segTree(1,sn); //從根節點開始編號&初始化

        ml=0;
        for(i=0;i<n;i++)
            ml=max(ml,insert_segTree(Re[t[i].s],1)); //從根節點開始插入

        printf("%d\n",ml);
    }

    return 0;
}

int cmp(const void *a, const void *b){
    T c = *(T *)a;
    T d = *(T *)b;
    if(c.e<d.e) return -1;
    if(c.e>d.e) return 1;
    return d.s-c.s;
}

void build_segTree(int l, int r){
    A[++segIndex].thisN=0;
    A[segIndex].lowB=l; //結點now 代表區間[l r]
    A[segIndex].upB=r;
    if(l==r)
        return;
    int m=(l+r)/2;
    build_segTree(l,m);
    build_segTree(m+1,r);
}

int insert_segTree(int ins, int now){
    if(ins<A[now].lowB) //整塊區間都在現在這個數ins的後面: 全部都算
        return A[now].thisN;

    if(A[now].upB<ins) //整塊區間在這個數前面: 不算
        return 0;

    if(A[now].lowB==A[now].upB) //segmentTree已經走到底了(這個數字自己的區間): 不包含自己
        return A[now].thisN++;

    if(A[now].lowB<=ins && ins<=A[now].upB){ //這個區間還沒切完: 左區間答案+右區間答案
        A[now].thisN++;
        return insert_segTree(ins, now+1)+insert_segTree(ins, (now+A[now].upB-A[now].lowB+2-((A[now].upB^A[now].lowB)&1)));
    }
}
```
天才版本
```
#include<stdio.h>
#include<stdlib.h>

#define MAX 20001
#define max(x,y) (x)>(y)?(x):(y)

typedef struct T{
    int low, high, num;
}T;

T t[MAX];
int s1[MAX],s2[MAX];

int cmp1(const void *a,const void *b){
    T c = *(T *)a;
    T d = *(T *)b;
    if(c.low!=d.low)
        return c.low-d.low;
    if(c.high!=d.high)
        return d.high-c.high;
    return c.num-d.num;
}

int cmp2(const void *a, const void *b){
    T c = *(T *)a;
    T d = *(T *)b;
    if(c.high!=d.high)
        return d.high-c.high;
    if(c.low!=d.low)
        return c.low-d.low;
    return c.num-d.num;
}

int main(){
    int N,i,m;
    while(scanf("%d",&N)!=EOF){
        for(i=0;i<N;i++){
            scanf("%d%d",&t[i].low,&t[i].high);
            t[i].num=i;
        }

        qsort(t,N,sizeof(T),cmp1);
        for(i=0;i<N;i++)
            s1[t[i].num]=i;

        qsort(t,N,sizeof(T),cmp2);
        for(i=0;i<N;i++)
            s2[t[i].num]=i;

        m=0;
        for(i=0;i<N;i++)
            m=max(m,N-1-s1[i]-s2[i]);

        printf("%d\n",m);
    }

    return 0;
}
```
