#include<stdio.h>
#include<math.h>

int main(){
    double T,D,H,tt,th,e;
    char W1[5],W2[5];

    while(scanf("%s",W1)!=EOF){
        if(W1[0]=='E')    break;
        scanf("%lf %s %lf",&tt,W2,&th);
        T=D=H=999.0;
        if(W1[0]=='T')  T=tt;
        else if(W1[0]=='D') D=tt;
        else if(W1[0]=='H') H=tt;

        if(W2[0]=='T')  T=th;
        else if(W2[0]=='D') D=th;
        else if(W2[0]=='H') H=th;

        if(T==999.0){
            e=6.11*pow(2.718281828,(5417.7530*((1/273.16)-(1/(D+273.16)))));
            T=H-((0.5555)*(e-10.0));
        }else if(D==999.0){
            e=(H-T)/(0.5555)+10.0;
            D=1/((1/273.16)-log(e/6.11)/5417.7530)-273.16;
        }else{
            e=6.11*pow(2.718281828,(5417.7530*((1/273.16)-(1/(D+273.16)))));
            H=T+(0.5555)*(e-10.0);
        }
        printf("T %.1lf D %.1lf H %.1lf\n",T,D,H);
    }

    return 0;
}
