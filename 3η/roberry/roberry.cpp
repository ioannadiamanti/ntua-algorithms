#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
	int id;
	int *adj;
}*nodes;

struct edge{
	int id,c,u,v,used;
}*E;

int maximum,orig=0;

int dfs(int source,int dest,int l,int cost){
	int res=0,i;
	if(source==dest) return 1;
	for(i=0;i<l;i++){
		if(nodes[source-1].adj[i]==1 && E[i].used==0 && E[i].c<=cost){
			E[i].used =1;
			if(source == E[i].u) res = dfs(E[i].v,dest,l,cost);
			else res = dfs(E[i].u,dest,l,cost);
			if (res){
				//cout<<"USED EDGE "<<E[i].u<<" " <<E[i].v<<endl;
				if(E[i].c>maximum) maximum=E[i].c;
				return 1;
			}
		}
	}
	return res;
}

int main(){
	int N,M,i,j,all=0,none=0;
	scanf("%d%d",&N,&M);
	nodes=(struct node*)malloc(N*sizeof(struct node));
	for(i=0;i<N;i++) nodes[i].adj = (int*)malloc(M*sizeof(int));
	E=(struct edge*)malloc(M*sizeof(struct edge));
	for(i=0;i<M;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].c);
		E[i].used=0;
		nodes[E[i].u-1].adj[i]=1;
		nodes[E[i].v-1].adj[i]=1;
	}
	for(i=0;i<M;i++){
		E[i].used=1;
		maximum=0;
		if(dfs(E[i].u,E[i].v,M,E[i].c)==0){
			//cout<<"WILL USE EDGE "<< E[i].u<< " "<<E[i].v<<endl;
			all++;
		}
		else if(E[i].c > maximum){
			none++;
			//cout<<"WONT USE EDGE "<< E[i].u<< " "<<E[i].v<<endl;
		}
		//if(E[i].u==2 && E[i].v == 7)cout<<maximum<<endl;
		for(j=0;j<M;j++)E[j].used=0;
	}
	cout<<all<<endl;
	cout<<none<<endl;
	cout<<M-all-none<<endl;
	return 0;
}		
