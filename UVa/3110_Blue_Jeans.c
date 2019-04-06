#include<stdio.h>
#include<string.h>

int main(){
    int t,n,i,j,s,e,l,f,k;
    char Word[10][61];
    char ans[61],base[61];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",Word[i]);
        ans[0]='\0';
        for(i=0;i<60;i++)
            for(j=i+2;j<60;j++){
                for(l=0,k=i;k<=j;k++)
                    base[l++]=Word[0][k];

                f=1;base[l]='\0';
                for(k=1;k<n;k++)
                    if(strstr(Word[k],base)==NULL){
                        f=0;break;
                    }
                if(f&&(strlen(base)>strlen(ans)||(strlen(base)==strlen(ans)&&strcmp(base,ans)<0)))
                    strcpy(ans,base);
            }
        if(ans[0]=='\0')    printf("no significant commonalities\n");
        else    printf("%s\n",ans);
    }

    return 0;
}
