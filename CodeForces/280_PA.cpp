#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);
    int sum=0;
    int level=0;
    for(int i=1;i<n;i++) {
        sum+=(i*(i+1))/2;
        if(sum>n)   break;
        else    level++;
    }

    if(n!=1)
        printf("%d\n",level);
    else    printf("1\n");

    return 0;
}
