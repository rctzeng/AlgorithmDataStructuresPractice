#include <stdio.h>

int main() {

    int x0,y0,x1,y1;
    scanf("%d%d%d%d", &x0,&y0,&x1,&y1);
    int a2,a3,b2,b3;
    int ax,ay,bx,by;
    long long int a0,b0;
    a2=a3=b2=b3=0;
    ax=x0;
    while((ax%2)==0) {
        ax/=2;
        a2++;
    }
    while((ax%3)==0) {
        ax/=3;
        a3++;
    }
    ay=y0;
    while((ay%2)==0) {
        ay/=2;
        a2++;
    }
    while((ay%3)==0) {
        ay/=3;
        a3++;
    }
    a0=ax*ay;

    bx=x1;
    while((bx%2)==0) {
        bx/=2;
        b2++;
    }
    while((bx%3)==0) {
        bx/=3;
        b3++;
    }
    by=y1;
    while((by%2)==0) {
        by/=2;
        b2++;
    }
    while((by%3)==0) {
        by/=3;
        b3++;
    }
    b0=bx*by;

    if(a0!=b0)  printf("-1\n");
    else {
        int r=b3-a3;
        int s=b2+r-a2;
        int fr=r;int fs=s;
        if(r<0) fr=-r;
        if(s<0) fs=-s;
        printf("%d\n", fr+fs);
        int axx,ayy,bxx,byy;
        axx=x0,ayy=y0,bxx=x1,byy=y1;
        if(r>0) {
            int tr=r;
            while((bxx%3)==0 && tr) {
                bxx/=3;bxx*=2;tr--;
            }
            while((byy%3)==0 && tr) {
                byy/=3;byy*=2;tr--;
            }
        } else if(r<0) {
            int tr=-r;
            while((axx%3)==0 && tr) {
                axx/=3;axx*=2;tr--;
            }
            while((ayy%3)==0 && tr) {
                ayy/=3;ayy*=2;tr--;
            }
        }
        if(s>0) {
            int ts=s;
            while((bxx%2)==0 && ts) {
                bxx/=2;ts--;
            }
            while((byy%2)==0 && ts) {
                byy/=2;ts--;
            }
        } else if(s<0) {
            int ts=-s;
            while((axx%2)==0 && ts) {
                axx/=2;ts--;
            }
            while((ayy%2)==0 && ts) {
                ayy/=2;ts--;
            }
        }
        printf("%d %d\n%d %d\n",axx,ayy,bxx,byy);
    }

    return 0;
}
