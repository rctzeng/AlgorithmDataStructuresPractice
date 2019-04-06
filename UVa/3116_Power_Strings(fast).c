#include<stdio.h>
#include<string.h>

#define MAX 1000001

int main(void){
    int i, n, len, p, c;
    char str[MAX];

    while (scanf("%s",str)!=EOF&&strcmp(str, ".")){
        c = -1;
        len = strlen(str);
        for (p=0, n=i=1;i<len;i++)
            if (p){
                if (str[i]!=str[i%c]){
                    p = 0;
                    n = 1;
                }
                else if (i%c==0)    n++;
            }else if (str[i]==str[0]){
                p = 1;
                c = i;
                n++;
            }

        if (n==1 || i%c)
            printf("1\n");
        else
            printf("%d\n", n);
    }

    return 0;
}
