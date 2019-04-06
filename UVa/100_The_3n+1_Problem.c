#include<stdio.h>

int main(){
	unsigned long n,i,a,b,c,cyc,max;
	while(scanf("%ld%ld",&a,&b)==2){
		printf("%ld %ld",a,b);
		if(a>b){
			c=a;a=b;b=c;
		}
		max=0;
		for(i=a;i<=b;i++){
			n=i;
			cyc=1;
			while(n!=1){
				n=n%2?3*n+1:n/2;
				cyc++;
			}
			max=cyc>max?cyc:max;
		}

		printf(" %ld\n",max);
	}

	return 0;
}
