# include <stdio.h>
# include <algorithm>

# define MAX 51

using namespace std;

int num[MAX];
int ctn, n;
int m;
// increase seq - decrease seq

void genPermutation();

int main() {

    scanf("%d%d", &n, &m);
    ctn = 0;
    for(int i=0;i<n;i++)
        num[i] = i+1;

    while(ctn!=m) {
        bool f = true;
        int i;
        // check for increase part
        for(i=0;i<n-1;i++) {
            if(num[i]>num[i+1])
                break;
        }
        // check for decrease part
        for(;i<n-1;i++) {
            if(num[i]<num[i+1]) {
                f = false;
                break;
            }
        }

        if(f) {
            ctn++;
            if(ctn == m)
                break;
        }

        genPermutation();
    }

    for(int i=0;i<n;i++)
        printf("%d ", num[i]);

    return 0;
}

void genPermutation() {
    int k,l;
    for(int i=0;i<n-1;i++)
        if(num[i]<num[i+1])
            k=i;

    for(int i=k;i<n;i++)
        if(num[k]<num[i])
            l=i;

    swap(num[k], num[l]);
    for(int i=0;i<=(n-1-(k+1))/2;i++)
        swap(num[k+1+i],num[n-1-i]);
}
