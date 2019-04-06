#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ERR 1e-10

typedef struct point{
    double x, y, z;
}pt;

pt p[8];

double dis(pt a,pt b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int cmp(const void *a, const void *b){
    pt c=*(pt *)a;
    pt d=*(pt *)b;
    if(c.z!=d.z)    return c.z-d.z;
    else if(c.y!=d.y)   return c.y-d.y;
    else    return c.x-d.x;
}

int check_inside(pt a);

int main(){
    int T;
    scanf("%d",&T);
    pt r,c,t;
    double R;
    while(T--){
        c.x=c.y=c.z=0.0;
        for(int i=0;i<8;i++){
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
            c.x+=p[i].x;
            c.y+=p[i].y;
            c.z+=p[i].z;
        }

        qsort(p,8,sizeof(pt),cmp);
        c.x/=8.0;c.y/=8.0;c.z/=8.0;
        scanf("%lf%lf%lf%lf",&r.x,&r.y,&r.z,&R);

        int f=1;
        for(int i=0;i<8;i++){
            if(dis(p[i],r)<R+ERR){
                f=0;break;
            }
        }
        if(f){
            double d=dis(c,r);
            t.x=r.x+(R/d)*(c.x-r.x);
            t.y=r.y+(R/d)*(c.y-r.y);
            t.z=r.z+(R/d)*(c.z-r.z);
            if(check_inside(t)==1)  f=0;
        }
        if(f){
            if(check_inside(r)==1){
                if(R+ERR>(r.x-p[0].x) ||R+ERR>(p[7].x-r.x)) f=0;
                if(R+ERR>(r.y-p[0].y) ||R+ERR>(p[7].y-r.y)) f=0;
                if(R+ERR>(r.z-p[0].z) ||R+ERR>(p[7].z-r.z)) f=0;
            }
        }

        if(f){
            if(r.x+ERR>p[0].x && r.x<p[7].x+ERR){
                if(r.y+ERR>p[0].y && r.y<p[7].y+ERR){
                    if(r.z<p[0].z+ERR){
                        if(r.z+R+ERR>p[0].z && r.z+R<p[7].z+ERR)    f=0;
                    }else if(r.z+ERR>p[7].z){
                        if(r.z-R+ERR>p[0].z && r.z+R<p[7].z+ERR)    f=0;
                    }
                }
            }
            if(r.z+ERR>p[0].z && r.z<p[7].z+ERR){
                if(r.y+ERR>p[0].y && r.y<p[7].y+ERR){
                    if(r.x<p[0].x+ERR){
                        if(r.x+R+ERR>p[0].x && r.x+R<p[7].x+ERR)    f=0;
                    }else if(r.x+ERR>p[7].x){
                        if(r.x-R+ERR>p[0].x && r.x+R<p[7].x+ERR)    f=0;
                    }
                }
            }
            if(r.x+ERR>p[0].x && r.x<p[7].x+ERR){
                if(r.z+ERR>p[0].z && r.z<p[7].z+ERR){
                    if(r.y<p[0].y+ERR){
                        if(r.y+R+ERR>p[0].y && r.y+R<p[7].y+ERR)    f=0;
                    }else if(r.y+ERR>p[7].y){
                        if(r.y-R+ERR>p[0].y && r.y+R<p[7].y+ERR)    f=0;
                    }
                }
            }
        }

        if(f)   puts("No");
        else    puts("Yes");
    }

    return 0;
}

int check_inside(pt t){
    if(t.x+ERR>p[0].x && t.x<p[7].x+ERR){
        if(t.y+ERR>p[0].y && t.y<p[7].y+ERR){
            if(t.z+ERR>p[0].z && t.z<p[7].z+ERR){
                return 1;
            }
        }
    }
    return 0;
}
