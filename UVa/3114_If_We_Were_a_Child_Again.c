#include<stdio.h>
#include<string.h>

int main(void){
    int n, i, j, k, l, len, d, mini, z;
    int a[1000], mul[10][1000], q[1000], b[15];
    char str[1000], ch;

    while(scanf("%s %c %d", str, &ch, &n)!=EOF){
        memset(mul, 0, sizeof(mul));
        memset(a, 0, sizeof(a));
        memset(q, 0, sizeof(q));
        memset(b, 0, sizeof(b));
        len = strlen(str);
        for (i=len-1;i>=0;i--)
            a[len-1-i] = str[i]-'0';
        for (i=0,k=n;k>0;i++){
            b[i] = k%10;
            k /= 10;
        }
        d = i;
        for (i=1;i<10;i++)
            for (j=0;j<=d;j++){
                mul[i][j] += mul[i-1][j]+b[j];
                if (mul[i][j]>=10){
                    mul[i][j] %= 10;
                    mul[i][j+1]++;
                }
            }

        for (i=0;i<=len-d;i++){
            q[i] = 9, mini = 0;
            for (j=1;j<10;j++){
                for (k=0;k<=d;k++){
                    if (a[len-i-k]<mul[j][d-k]){
                        q[i] = j-1;
                        mini = 1;
                        break;
                    }else if (a[len-i-k]>mul[j][d-k])
                        break;
                }
                if (mini)
                    break;
            }
            for (l=d;l>=0;l--){
                a[len-i-l] -= mul[q[i]][d-l];
                if (a[len-i-l]<0){
                    a[len-i-l]+=10;
                    a[len-i-l+1]--;
                }
            }
        }

        if (ch=='/'){
            for (z=i=0;i<=len-d;i++){
                if (q[i]!=0 || i==len-d)
                    z = 1;
                if (z)
                    printf("%d", q[i]);
            }
            if (len-d<0)
                printf("0");
            printf("\n");
        }else if (ch=='%'){
            for (z=0,i=d;i>=0;i--){
                if (a[i]!=0 || !i)
                    z = 1;
                if (z)
                    printf("%d", a[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
