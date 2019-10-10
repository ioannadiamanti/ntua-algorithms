#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;


int A[101][101];
long long int V[11][101][101];

void findcost(int from,int N,int K){
	int explored[N+1],i,j,z,minv,l;
	long long int min;
	for(i=0;i<=K;i++) V[i][from][from]=0;
	for(l=0;l<=K;l++){
		memset(explored,0,(N+1)*sizeof(int));
		for(z=0;z<N-1;z++){
			min=100000000;
			minv=1;
			for(j=1;j<=N;j++){
				if(V[l][j][from]<min && explored[j]==0){
					min=V[l][j][from];
					minv = j;
				}
			}
			explored[minv]=1;
			for(j=1;j<=N;j++){
				if(A[minv][j]!=1000001 && explored[j]==0){
					if(V[l][minv][from]+A[minv][j]<V[l][j][from]){
						V[l][j][from]=V[l][minv][from]+A[minv][j];
					}
				}
			}
			if(l<K){
				for(i=1;i<=N;i++){
					if(A[i][minv]!=1000001 && explored[i]==0){
						if(V[l][minv][from]+A[i][minv]<V[l+1][i][from]){
							V[l+1][i][from]=V[l][minv][from]+A[i][minv];
						}
					}
				}
			}
		}		
	}
}

int main(){
	int N,M,K,Q,i,j,z,d,from,to,p,*calculated;
	long long int *ret;
	scanf("%d %d %d %d",&N,&M,&K,&Q);
	calculated=(int*)malloc((N+1)*sizeof(int));
	memset(calculated,0,(N+1)*sizeof(int));
	ret=(long long int*)malloc(Q*sizeof(long long int));
	for(i=0;i<101;i++){
		for(j=0;j<101;j++){
			A[i][j]=1000001;
		}
	}
	for(i=1;i<=M;i++){
		scanf("%d",&from);
		scanf("%d",&to);
		scanf("%d",&d);
		A[from][to]=d;
	}
	for(i=0;i<=K;i++){
		for(j=0;j<=N;j++){
			for(z=0;z<=N;z++){
				V[i][j][z]=100000000;
			}
		}
	}
	for(i=0;i<Q;i++){
		scanf("%d",&from);
		scanf("%d",&to);
		scanf("%d",&p);
		if(from==to) ret[i]=0;
		else if(calculated[from]){
			ret[i] = V[0][to][from];
			for(j=1;j<=p;j++){
				if(V[j][to][from]<ret[i]) ret[i]=V[j][to][from];
			}
		}
		else{
			calculated[from]=1;
			findcost(from,N,K);
			ret[i] = V[0][to][from];
			for(j=1;j<=p;j++){
				if(V[j][to][from]<ret[i]) ret[i]=V[j][to][from];
			}
		}		
	}
	for(i=0;i<Q;i++){
		if(ret[i]==100000000)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ret[i]<<endl;
	}
	return 0;
}
