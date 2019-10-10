#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct box{
	long long int bridge,ex,ey,num[100];
}b[180][180];

int main(){
	long long int N,M,K,X,i,j,l,s,e,result=0;
	scanf("%lld%lld%lld%lld",&N,&M,&K,&X);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			b[i][j].bridge=0;
			for(l=0;l<K;l++){
				b[i][j].num[l]=0;
			}
		}
	}
	b[N-1][M-1].num[0]=1;
	for(i=0;i<K;i++){
		scanf("%lld%lld",&s,&e);
		b[s/M][s%M].bridge=1;
		b[s/M][s%M].ex=e/M;
		b[s/M][s%M].ey=e%M;
	}
	for(j=M-1;j>=0;j--){
		for(i=N-1;i>=0;i--){
			if(b[i][j].bridge == 0 && j>0 && i>0){
				for(l=0;l<=X;l++){
					b[i-1][j].num[l]+=b[i][j].num[l]%1000000103;
					b[i][j-1].num[l]+=b[i][j].num[l]%1000000103;
				}
			}
			else if(b[i][j].bridge == 0 && i==0 && j>0){
				for(l=0;l<=X;l++) b[i][j-1].num[l]+=b[i][j].num[l]%1000000103;
			}
			else if(b[i][j].bridge == 0 && j==0 && i>0){
				for(l=0;l<=X;l++) b[i-1][j].num[l]+=b[i][j].num[l]%1000000103;
			}
			else if(b[i][j].bridge == 1){
				for(l=1;l<=X;l++) b[b[i][j].ex][b[i][j].ey].num[l]+=b[i][j].num[l-1]%1000000103;
			}
		}
	}	
	for(i=0;i<=X;i++) result+=b[0][0].num[i];
	cout<<result%1000000103<<endl;
	return 0;
}	
