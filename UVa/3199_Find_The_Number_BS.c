#include<stdio.h>
#include<string.h>

long long int dep[13],ldep[13],k;
long long int Table[13][1001];

void DFS(int num,int now, int i, long long int nmul);
int Find(long long int n,long long int num);
long long int gcd(long long int a,long long int b);

int main(){
    int t,n,i,j,a,f;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&k,&n);
        for(i=1;i<=k;i++)    scanf("%lld",&dep[i]);
        memset(Table,0,sizeof(Table));
        memset(ldep,0,sizeof(ldep));
        for(i=1;i<=k;i++)
            DFS(i,0,0,1);

        long long int l,r,m;
        l=2,r=1e15;
        while(l+1<r){
            m=(l+r)/2;
            a=Find(m,n);
            if(a==1)
                r=m;
            else if(a==-1)
                l=m;
            else
                break;
        }
        long long int ii;
        for(ii=m;ii>=0;ii--){
            f=0;
            for(j=1;j<=k;j++)
                if(!(ii%dep[j]))    f++;
            if(f==1)    break;
        }
        printf("%lld\n",ii);
    }

    return 0;
}

void DFS(int num,int now, int i, long long int nmul){
    if(now==num){
        Table[num][ldep[num]++]=nmul;
        return;
    }
    int j;long long int t;
    for(j=i+1;j<=k;j++){
        t=nmul*dep[j]/gcd(nmul,dep[j]);
        if(t>=nmul)
            DFS(num,now+1,j,t);
    }
}

long long int gcd(long long int a,long long int b){
    while((a%=b)&&(b%=a));
    return a+b;
}

int Find(long long int n,long long int num){
    int i,j;long long int ct=0;
    for(i=1;i<=k;i++){
        if(i%2)
            for(j=0;j<ldep[i];j++)
                ct+=i*(n/Table[i][j]);
        else
            for(j=0;j<ldep[i];j++)
                ct-=i*(n/Table[i][j]);
    }
    if(ct>num)  return 1;
    else if(ct<num) return -1;
    else    return 0;
}
