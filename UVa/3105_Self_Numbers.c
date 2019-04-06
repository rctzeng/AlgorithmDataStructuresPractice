#include<stdio.h>

#define MAX 10000

int Self_Num[MAX];

int main(){
    int i,i1,i2,i3,i4;
    for(i1=0;i1<10;i1++)
        for(i2=0;i2<10;i2++)
            for(i3=0;i3<10;i3++)
                for(i4=0;i4<10;i4++)
                    Self_Num[i1*1001+i2*101+i3*11+i4+i4]=1;

    for(i=1;i<MAX;i++)
        if(!Self_Num[i])
            printf("%d\n",i);

    return 0;
}
