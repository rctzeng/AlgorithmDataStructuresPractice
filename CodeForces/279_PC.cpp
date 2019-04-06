#include <stdio.h>
#include <string.h>

#define MAX 1000001

char str[MAX];
int sk1[MAX];
int k1;
int pos[MAX];

int main() {
    while(scanf("%s", str)!=EOF) {
        memset(pos,0,sizeof(pos));
        int a, b;
        scanf("%d%d", &a,&b);
        int l=strlen(str);
        int t=1;
        int left1=-1;
        k1=0;
        for(int i=0;i<l;i++) {
            if(left1==-1)   left1=(str[i]-'0')%a;
            else    left1=(left1*10+(str[i]-'0'))%a;
            if(left1==0)    sk1[k1++]=i;
        }

        int left2=-1;
        t=1;
        for(int i=l-1;i>=0;i--) {
            t%=b;
            if(left2==-1) {
                left2=((str[i]-'0')*t)%b;
            } else {
                left2=(left2+(str[i]-'0')*t)%b;
            }

            if(left2==0 && str[i]!='0')    pos[l-i]=1;
            t*=10;
        }

        int ans=-1;
        for(int i=0;i<k1;i++) {
            if(pos[l-sk1[i]-1]==1) {
                ans=sk1[i];
                break;
            }
        }

        if(ans>=0) {
            printf("YES\n");
            for(int i=0;i<=ans;i++)
                printf("%c",str[i]);
            printf("\n");
            for(int i=ans+1;i<l;i++)
                printf("%c",str[i]);
        } else  printf("NO\n");
    }
}
