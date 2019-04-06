#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

int X[MAX], A[MAX], T[MAX], Calc[MAX], Next[MAX], ln, lc, lt, la;

void mul(int dig);
int compare(int *x, int *y, int lx, int ly);
void sub();
void add(int dig);

int main() {
    int t;
    scanf("%d", &t);
    char s[MAX];
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        memset(X, 0, sizeof(X));
        memset(Next, 0, sizeof(Next));ln=0;
        memset(A, 0, sizeof(A));la=0;
        memset(Calc,0,sizeof(Calc));lc=0;
        for(int i=0;i<l;i++)    X[l-1-i] = s[i]-'0';
        int now = l-1;
        while(now >= 0){
            //add 2 digit to remain
            for(int i=ln-1;i>=0;i--)
                Next[i+1]=Next[i];
            Next[0] = X[now--];
            ln++;

            if((now+1)%2) {
                for(int i=ln-1;i>=0;i--)
                    Next[i+1]=Next[i];
                Next[0] = X[now--];
                ln++;
            }
            //guess 0-9
            int d = 0, ca;
            for(int i=0;i<=9;i++) {
                mul(i);
                ca = compare(T, Next, lt, ln);
                if(ca == -1) d=i;
                else if (ca == 0) {
                    d=i;break;
                }else   break;
            }

            //substract and update
            mul(d);
            sub();
            add(d);
            A[la++] = d;
        }

        for(int i=0;i<la;i++)    printf("%d",A[i]);
        printf("\n");
        if(t)    printf("\n");
    }

    return 0;
}

int compare(int *x, int *y, int lx, int ly) {
    if(lx < ly) return -1;
    else if(lx > ly)    return 1;
    for(int i=lx-1;i>=0;i--) {
        if(x[i]<y[i])   return -1;
        else if(x[i]>y[i])  return 1;
    }
    return 0;
}

void mul(int dig) {
    memset(T, 0, sizeof(T));
    for(int i=lc-1;i>=0;i--)  T[i+1] = Calc[i];
    T[0] = dig;
    lt=lc+1;
    for(int i=0;i<lt;i++)
        T[i] *= dig;
    int c=0,t;
    for(int i=0;i<lt;i++) {
        t=c+T[i];
        c=t/10;
        T[i]=t%10;
    }
    if(c) {
        T[lt++] = c%10;
        c/=10;
    }
}

void sub() {
    int c=0;
    for(int i=0;i<ln;i++) {
        Next[i]-=c+T[i];
        c=0;
        if(Next[i]<0) {
            c=1;Next[i]+=10;
        }
    }

    int dig = 0;
    for(int i=0;i<ln;i++)
        if(Next[i]) dig=i;
    if(!Next[dig])  ln=0;
    else    ln = dig+1;
}

void add(int dig) {
    for(int i=lc-1;i>=0;i--)   Calc[i+1]=Calc[i];
    Calc[0]=dig*2;
    lc++;
    int c=0, t;
    for(int i=0;i<lc;i++) {
        t=c+Calc[i];
        c=t/10;
        Calc[i]=t%10;
    }
    if(c)
        Calc[lc++]=c;
}
