#include <stdio.h>
#include <string.h>

int main() {
    char S[101];
    char F[10] = {'C', 'O', 'D', 'E', 'F', 'O', 'R', 'C', 'E', 'S'};
    scanf("%s", S);
    int l = strlen(S);
    int s=0, e=0;
    for(int i=0;i<l;i++) {
        if(F[s]==S[i])  s++;
        else    break;
    }
    for(int i=0;i<l;i++) {
        if(F[9-e]==S[l-1-i])    e++;
        else    break;
    }

    if(s+e >= 10)   printf("YES\n");
    else    printf("NO\n");


    return 0;
}
