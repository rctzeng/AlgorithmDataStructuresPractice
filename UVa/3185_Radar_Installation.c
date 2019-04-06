#include<stdio.h>

#define MAX 1001

typedef struct point{
    int x,y;
}point;

point Island[MAX];

int main(){
    char str[10];
    int x,y,n,t;
    t=0;
    while(gets(str)!=NULL){
        if(str[0]='\0'){



            n=0;
            printf("Case %d: ",++t);
        }else{
            sscanf("%d%d",&x,&y);
            if(x+y==0)  break;
            Island[n].x=x;Island[n++].y=y;
        }
    }

    return 0;
}
