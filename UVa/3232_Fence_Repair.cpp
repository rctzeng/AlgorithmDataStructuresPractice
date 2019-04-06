#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

#define MAX 20001

using namespace std;

long long int F[MAX];

int main(){
    int N,i;
    long long int a,b,sum;
    while(scanf("%d",&N)!=EOF){
        for(i=0;i<N;i++)    scanf("%lld",&F[i]);
        sum=0;
        vector<long long int> v(F,F+N);
        make_heap(v.begin(),v.end(),greater<long long int>());
        while(v.size()>1){
            a=v.front();
            pop_heap(v.begin(),v.end(),greater<long long int>());v.pop_back();
            b=v.front();
            pop_heap(v.begin(),v.end(),greater<long long int>());v.pop_back();
            sum+=a+b;
            v.push_back(a+b);
            push_heap(v.begin(),v.end(),greater<long long int>());
        }

        printf("%lld\n",sum);
    }

    return 0;
}
