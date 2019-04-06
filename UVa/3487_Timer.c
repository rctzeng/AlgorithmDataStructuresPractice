#include<stdio.h>
#include<math.h>

double cal(double a, double R, double H);

int main(){
    int T;
    scanf("%d",&T);
    double H,D,V,R;
    while(T--){
        scanf("%lf%lf%lf",&H,&D,&V);
        R=D/2.0;
        double l=0, r=D, mid;
        while(r-l>=1e-7){
            mid=(l+r)/2;
            if(cal(mid,R,H)<V)
                l=mid;
            else    r=mid;
        }

        printf("%.5lf\n", D-mid);
    }

    return 0;
}

double cal(double a, double R, double H){
    return H*R*R*acos((R-a)/R)/3.0-H*(R-a)*sqrt(R*R-(R-a)*(R-a))*2.0/3.0+H*(R-a)*(R-a)*(R-a)/R*log((sqrt(R*R-(R-a)*(R-a))+R)/(R-a))/3.0;
}
