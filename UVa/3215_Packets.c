#include<stdio.h>

int u[4]={0,5,3,1};
int BoxN[7];

int main(){
    int volume,boxNeed,a,b,c;
    while(~scanf("%d%d%d%d%d%d",&BoxN[1],&BoxN[2],&BoxN[3],&BoxN[4],&BoxN[5],&BoxN[6])&&(BoxN[1]+BoxN[2]+BoxN[3]+BoxN[4]+BoxN[5]+BoxN[6])){
        boxNeed=BoxN[6]+BoxN[5]+BoxN[4]+(3+BoxN[3])/4;
        a=BoxN[4]*5+u[BoxN[3]%4];
        if(a<BoxN[2])
            boxNeed+=(BoxN[2]-a+8)/9;
        b=boxNeed*36-BoxN[2]*4-BoxN[3]*9-BoxN[4]*16-BoxN[5]*25-BoxN[6]*36;
        if(b<BoxN[1])
            boxNeed+=(BoxN[1]-b+35)/36;

        printf("%d\n",boxNeed);
    }

    return 0;
}
