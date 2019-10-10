#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h> 
#include <stack> 
using namespace std;

vector<int> A[30001];
vector<int> T[30001];

int sum=0;
void dfs(int v,bool visited[]){
	vector<int>::iterator i;
	int j;
	visited[v] = true;
	sum++;
	for (i = T[v].begin(); i != T[v].end(); ++i) {
		if (!visited[*i]){
			visited[*i]=true;
			dfs(*i,visited); 
		}
	}
}

void fillStack(int v, bool visited[], stack<int> &Stack) 
{ 
	visited[v] = true; 
	vector<int>::iterator i;
	for(i = A[v].begin(); i != A[v].end(); ++i) 
		if(!visited[*i]) 
			fillStack(*i, visited, Stack); 
	Stack.push(v); 
}

void find_scc(int N,bool visited[]){
	int i,v;
	stack<int> Stack;
        vector<int>::iterator j;
	for(i=1;i<=N;i++) visited[i] = false;
	for(i=1;i<=N;i++) 
		if(!visited[i]) 
			fillStack(i, visited, Stack); 
	for (i=1;i<=N;i++)
	        for(j=A[i].begin(); j!=A[i].end(); ++j) 
	        	T[*j].push_back(i);
	for(i=1;i<=N;i++) visited[i] = false;
	dfs(Stack.top(),visited); 
}

int main(){
	int i,j,N,temp,temp2;
	bool *visited,flag;
	scanf("%d",&N);
	visited=(bool*)malloc((N+1)*sizeof(bool));
	for(i=1;i<=N;i++){
		scanf("%d",&temp);
		for(j=1;j<=temp;j++){
			scanf("%d",&temp2);
			A[temp2].push_back(i);
		}
	}
	find_scc(N,visited);
	cout<<sum<<endl;
	return 0;
}
