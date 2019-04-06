#include<stdio.h>

int Direc[4][2]={{1,0},{1,-1},{1,1},{0,1}};
int Chess[20][20];

int main(){
    int T,i,j,k,l,x,y;
    scanf("%d",&T);
    while(T--){
        for(i=1;i<20;i++)
            for(j=1;j<20;j++)
                scanf("%d",&Chess[i][j]);
        for(j=1;j<20;j++){
            for(i=1;i<20;i++){
                if(Chess[i][j]==0)  continue;
                for(k=0;k<4;k++){
                    x=j-Direc[k][0];
                    y=i-Direc[k][1];
                    if(x>0&&x<20&&y>0&&y<20)
                        if(Chess[y][x]==Chess[i][j])
                            continue;
                    x=j+Direc[k][0]*5;
                    y=i+Direc[k][1]*5;
                    if(x>0&&x<20&&y>0&&y<20)
                        if(Chess[y][x]==Chess[i][j])
                            continue;

                    x=j+Direc[k][0]*4;
                    y=i+Direc[k][1]*4;
                    if(x>0&&x<20&&y>0&&y<20){
                        y=i;x=j;
                        for(l=1;l<5;l++){
                            x+=Direc[k][0];
                            y+=Direc[k][1];
                            if(Chess[y][x]!=Chess[i][j])
                                break;
                        }
                        if(l==5)
                            break;
                    }else   continue;
                }
                if(k<4) break;
            }
            if(i<20)    break;
        }
        if(i<20&&j<20)  printf("%d\n%d %d\n",Chess[i][j],i,j);
        else    printf("0\n");
    }

    return 0;
}
