#include<stdio.h>
#include<string.h>

#define MAX 10001

int main(){
    int t, i, n, a, b, par[MAX], visit[MAX];
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i=0;i<=n;i++)  par[i] = visit[i] = 0;
        for (i=0;i<n-1;i++){
            scanf("%d %d", &a, &b);
            par[b] = a;
        }
        scanf("%d %d", &a, &b);

        while (a!=0){
            visit[a] = 1;
            a = par[a];
        }
        while (b!=0){
            if (visit[b]){
                printf("%d\n", b);
                break;
            }
            b = par[b];
        }
    }

    return 0;
}
