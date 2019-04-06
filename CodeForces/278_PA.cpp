#include <stdio.h>

#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

#define MAX 1001

int main() {
    int Hy,Ay,Dy,Hm,Am,Dm,h,a,d;
    scanf("%d%d%d%d%d%d%d%d%d", &Hy,&Ay,&Dy,&Hm,&Am,&Dm,&h,&a,&d);

    int ans=-1;
    for(int mh=0;mh<MAX;mh++) {
        int tans=-1;
        // beating duration
        for(int k=1;k<MAX;k++) {
            int md=-1,ma=-1;
            // Yang's HP
            for(int j=0;j<MAX;j++) {
                int hurt=max(0,Am-(j+Dy));
                int t=Hy+mh-k*hurt;
                if(t>0) {
                    md=j;break;
                }
                if(hurt==0) break;
            }
            // Monster's HP
            for(int j=0;j<MAX;j++) {
                int hurt=max(0,Ay+j-Dm);
                int t=Hm-k*hurt;
                if(t<=0) {
                    ma=j;break;
                }
            }
            if(md!=-1 && ma!=-1) {
                if(tans!=-1)    tans=min(tans,h*mh+a*ma+d*md);
                else    tans=h*mh+a*ma+d*md;
            }
        }
        if(tans!=-1) {
            if(ans!=-1) ans=min(tans,ans);
            else  ans=tans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
