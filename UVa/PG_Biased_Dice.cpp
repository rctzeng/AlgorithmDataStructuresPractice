#include<stdio.h>
#include<string.h>
#define MAX 101

int T[5][2]={{0,0},{-1,0},{0,-1},{0,1},{1,0}}; //L, F, B, R

typedef struct dice{
	int f[6];
}dice;

dice D[MAX];

int maph[MAX+MAX][MAX+MAX][2]; //[0] for height, [1] for top
int number[6]; //top

void creatD(int num, int t, int f);
void moveR(dice *a);
void moveL(dice *a);
void moveF(dice *a);
void moveB(dice *a);
void moveRr(dice *a);

int main(){
	int n,i,j,k,l,f,t,movef,nextF,x,y;
	while(scanf("%d",&n)!=EOF && n){
		for(i=0;i<2*MAX+1;i++)
			for(j=0;j<2*MAX+1;j++){
				maph[i][j][0]=0;
				maph[i][j][1]=-1;
			}

		memset(number,0,sizeof(number));
		scanf("%d%d",&t,&f);
		creatD(0,t,f);
		maph[100][100][0]++;
		maph[100][100][1]=D[0].f[0];
		number[D[0].f[0]]++;

		for(i=1;i<n;i++){
			scanf("%d%d",&t,&f);
			creatD(i,t,f);
			movef=1;
			x=y=100;
			maph[x][y][0]++;
			while(movef){
				nextF=-1;
				for(j=5;j>=3;j--){
					for(k=1;k<=4;k++){
						if(D[i].f[k]==j && maph[x][y][0] > maph[x+T[k][0]][y+T[k][1]][0]+1){
							nextF=k;
							break;
						}
					}
					if(nextF!=-1)
						break;
				}

				if(nextF==-1){
					if(maph[x][y][1]!=-1){
						number[maph[x][y][1]]--;
						number[D[i].f[0]]++;
						maph[x][y][1]=D[i].f[0];
					}else{
                        maph[x][y][1]=D[i].f[0];
                        number[D[i].f[0]]++;
					}
					movef=0;
				}else{
					if(nextF==1){
						moveL(&D[i]);
						maph[x][y][0]--;
						maph[--x][y][0]++;
					}else if(nextF==2){
						moveF(&D[i]);
						maph[x][y][0]--;
						maph[x][--y][0]++;
					}else if(nextF==3){
						moveB(&D[i]);
						maph[x][y][0]--;
						maph[x][++y][0]++;
					}else if(nextF==4){
						moveR(&D[i]);
						maph[x][y][0]--;
						maph[++x][y][0]++;
					}
				}
			}
		}

		for(i=0;i<6;i++){
			printf("%d",number[i]);
			if(i!=5)	printf(" ");
			else
				printf("\n");
		}
	}

	return 0;
}

void creatD(int num, int t, int f){
	dice t1,t2,t3;
	int i,j,ij,k,flag;
	for(i=0;i<6;i++)
		t1.f[i]=i;
	for(i=0;i<4;i++){
        for(k=0;k<6;k++)	t3.f[k]=t1.f[k];
        for(ij=0;ij<4;ij++){
            for(k=0;k<6;k++)	t2.f[k]=t3.f[k];
            for(j=0;j<4;j++){
                flag=0;
                if(t2.f[0]==t-1 && t2.f[2]==f-1){
                    for(k=0;k<6;k++)	D[num].f[k]=t2.f[k];
                    flag=1;
                }
                if(flag)	break;
                moveR(&t2);
            }
            if(flag)    break;
            moveRr(&t3);
		}
		if(flag)	break;
		moveF(&t1);
	}
}

void moveRr(dice *a){
    dice t;
	t.f[0]=a->f[0];
	t.f[1]=a->f[3];
	t.f[2]=a->f[1];
	t.f[3]=a->f[4];
	t.f[4]=a->f[2];
	t.f[5]=a->f[5];
	int i;
	for(i=0;i<6;i++)
		a->f[i]=t.f[i];
}

void moveR(dice *a){
	dice t;
	t.f[0]=a->f[1];
	t.f[1]=a->f[5];
	t.f[2]=a->f[2];
	t.f[3]=a->f[3];
	t.f[4]=a->f[0];
	t.f[5]=a->f[4];
	int i;
	for(i=0;i<6;i++)
		a->f[i]=t.f[i];
}
void moveL(dice *a){
	dice t;
	t.f[0]=a->f[4];
	t.f[1]=a->f[0];
	t.f[2]=a->f[2];
	t.f[3]=a->f[3];
	t.f[4]=a->f[5];
	t.f[5]=a->f[1];
	int i;
	for(i=0;i<6;i++)
		a->f[i]=t.f[i];
}
void moveB(dice *a){
	dice t;
	t.f[0]=a->f[2];
	t.f[1]=a->f[1];
	t.f[2]=a->f[5];
	t.f[3]=a->f[0];
	t.f[4]=a->f[4];
	t.f[5]=a->f[3];
	int i;
	for(i=0;i<6;i++)
		a->f[i]=t.f[i];
}
void moveF(dice *a){
	dice t;
	t.f[0]=a->f[3];
	t.f[1]=a->f[1];
	t.f[2]=a->f[0];
	t.f[3]=a->f[5];
	t.f[4]=a->f[4];
	t.f[5]=a->f[2];
	int i;
	for(i=0;i<6;i++)
		a->f[i]=t.f[i];
}
