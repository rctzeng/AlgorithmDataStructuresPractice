#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 4000000

using namespace std;

char str[MAX][11];

int cmp(const void *a, const void *b){
    return *(char *)a-*(char *)b;
}

int main(){
    char temp[11];
    int i,n,l,t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",temp);
        l=strlen(temp);
        qsort(temp,l,sizeof(char),cmp);
        strcpy(str[0],temp);n=0;
        while(next_permutation(temp,temp+l)!=0)
            strcpy(str[++n],temp);

        for(i=0;i<=n;i++)
            printf("%s\n",str[i]);
        printf("\n");
    }
    return 0;
}
