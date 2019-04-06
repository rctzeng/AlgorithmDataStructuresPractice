#include<stdio.h>

#define MAX 1501

int Ugly[MAX];

int main(){
    int i,now,i2,i3,i5; Ugly[0]=1;
    i2=i3=i5=0;
    for(i=1;i<MAX;i++){
        while(Ugly[i2]*2<=Ugly[i-1])    i2++;
        while(Ugly[i3]*3<=Ugly[i-1])    i3++;
        while(Ugly[i5]*5<=Ugly[i-1])    i5++;
        now=Ugly[i2]*2;
        if(Ugly[i3]*3<now)  now=Ugly[i3]*3;
        if(Ugly[i5]*5<now)  now=Ugly[i5]*5;
        Ugly[i]=now;
    }

    printf("The 1500'th ugly number is %d.\n",Ugly[1499]);

    return 0;
}
