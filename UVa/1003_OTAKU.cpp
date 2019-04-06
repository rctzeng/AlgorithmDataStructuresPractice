#include<stdio.h>
#include<string>
#include<map>

using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d",&n,&m);
    map<string, bool> feature;
    char str[20];
    for(int i=0;i<n;i++){
        scanf("%s",str);
        feature[str]=false;
    }
    while(m--){
        scanf("%d",&k);
        int c=0;
        for(int i=0;i<k;i++){
            scanf("%s",str);
            if(feature.find(str)!=feature.end())    c++;
        }
        if(c*2>k)   puts("Y");
        else    puts("N");
    }

    return 0;
}
