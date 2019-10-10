#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

long long int f(int a,int b,int c,long long int x){
	return a*x*x+b*x+c;
}

int main(){
	int N,a,b,c,*x,i,j,index;
	long long int *p,max,sum,temp,maxp,y;
	scanf("%d %d %d %d",&N,&a,&b,&c);
	x = (int*)malloc((N+1)*sizeof(int));
	p = (long long int*)malloc((N+1)*sizeof(long long int));
	x[0]=0;
	p[0]=0;
	for (i=1;i<=N;i++) scanf("%d",&x[i]);
	p[1]=a*x[1]*x[1]+b*x[1]+c;
	maxp=p[1];
	index=1;
	for(i=2;i<N+1;i++){
		max=p[i-1]+f(a,b,c,x[i]);
		sum=x[i];
		for(j=i-1;j>0;j--){
			sum+=x[j];
			if(sum > -b/(2*a) && sum-x[j] < -b/(2*a)) y= f(a,b,c,sum-x[j]);
			temp=p[j-1]+f(a,b,c,sum);
			if(max<temp) max = temp;
			if(sum>-b/(2*a) && j-1<index && f(a,b,c,sum)< y) break;
		}
		p[i]=max;
		if(p[i]>=maxp){
			maxp=p[i];
			index=i;
		}
	}
	//for(i=1;i<=N;i++)cout<<p[i]<<" ";
	//cout<<endl;
	cout<<p[N]<<endl;
	return 0;
}
