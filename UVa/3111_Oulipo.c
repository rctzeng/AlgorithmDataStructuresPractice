#include<stdio.h>
#include<string.h>

char W[10001],T[1000001];
int suffix[1000001];

int main(){
    int t,i,j,c,lw,lt,f;
    scanf("%d",&t);
    while(t--){
        scanf("%s",W);lw=strlen(W);
        scanf("%s",T);lt=strlen(T);
        c=0;j=0;
        suffix[0]=-1;suffix[1]=0;
        for(i=2;i<=lw;i++){
            while(j>=0&&W[j]!=W[i-1])
                j=suffix[j];
            suffix[i]=++j;
        }

        i=0;j=0;
        while(i<lt){
            if(W[j]==T[i]){
                i++;j++;
            }else if(j>=0){
                j=suffix[j];
            }else{
                i++;j=0;
            }
            if(j==lw){
                c++;j=suffix[j];
            }
        }

        printf("%d\n",c);
    }

    return 0;
}
