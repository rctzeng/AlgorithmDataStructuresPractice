#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int in[8][8], n=0, i,j,k,valid,conPos[10],order[10];
    while(~scanf("%d%d%d%d%d%d",&in[0][0],&in[0][1],&in[0][2],&in[0][3],&in[0][4],&in[0][5])){
        for(i=1;i<7;i++)
            for(j=0;j<6;j++)
                scanf("%d",&in[i][j]);

        for(i=0;i<7;i++)
            order[i]=i;
        while(next_permutation(order,order+7)){
            for(i=1;i<7;i++)
                for(j=0;j<6;j++)
                    if(in[order[0]][i-1]==in[order[i]][j])
                        conPos[i]=j;
            for(i=1,valid=1;valid&&i<7;i++)
                if(in[order[i]][(conPos[i]+5)%6]!=in[order[i%6+1]][(conPos[i%6+1]+1)%6])
                    valid=0;
            if(valid)
                break;
        }
        if(valid)   puts("YES");
        else    puts("NO");
    }

    return 0;
}
