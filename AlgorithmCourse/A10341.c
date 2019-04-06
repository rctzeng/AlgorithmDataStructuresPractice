#include<stdio.h>
#include<math.h>

#define err 1e-7

double p,q,r,s,t,u;

double compute(double x);

int main() {
    while(scanf("%lf%lf%lf%lf%lf%lf", &p,&q,&r,&s,&t,&u)!=EOF) {
        double l=0, r=1, m;
        if(compute(l)*compute(r) > 0) {
            printf("No solution\n");
            continue;
        }

        while(l+err < r) {
            m = (r+l)/2;
            double fl = compute(l);
            double fm = compute(m);

            if(fl*fm <= 0) {
                r = m;
            } else {
                l = m;
            }
        }
        printf("%.4f\n", r);
    }

    return 0;
}

double compute(double x) {
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
