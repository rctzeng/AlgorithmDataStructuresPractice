#include<stdio.h>

void print(int a,int b);

int main(){
    int T;
    int N,K,n2,n3,n4;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        if(N%2) n2=N/2+1;
        else    n2=N/2;
        if(N%3) n3=N/3+1;
        else    n3=N/3;
        if(N%4) n4=N/4+1;
        else    n4=N/4;

        if(K<=n2)
            print(1,N-K+1);
        else if(K<=n2+n3)
            print(2,N-(K-n2)+1);
        else if(K<n2+n3+n4)
            print(3,N-(K-n2-n3)+1);
        else    print(4,N-(K-n2-n3-n4)+1);
    }

    return 0;
}

void print(int a,int b){
    int d,ta=a,tb=b;
    while((ta%=tb)&&(tb%=ta));
    d=ta+tb;
    printf("%d/%d\n",a/d,b/d);
}
