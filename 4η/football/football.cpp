#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h> 
using namespace std;

vector<int> A[30001];

void dfs(int v,bool visited[]){
	vector<int>::const_iterator i;
	int j;
	for (i = A[v].begin(); i != A[v].end(); ++i) {
		if (!visited[*i]){
			visited[*i]=true;
			dfs(*i,visited); 
		}
	}
}

int main(){
	int i,j,N,temp,temp2,sum=0;
	bool *visited,flag;
	//vector<int>::const_iterator k;
	scanf("%d",&N);
	visited=(bool*)malloc((N+1)*sizeof(bool));
	for(i=1;i<=N;i++){
		scanf("%d",&temp);
		for(j=1;j<=temp;j++){
			scanf("%d",&temp2);
			A[temp2].push_back(i);
		}
	}
	/*for (int v = 1; v <= N; v++){ 
	       for(k = A[v].begin(); k != A[v].end(); ++k) {
  		  cout << *k <<" ";
  		}
  		cout << endl;
    	} */
	for(i=1;i<=N;i++){
		flag=true;
		memset(visited,0,(N+1)*sizeof(bool));
		visited[i]=true;
		dfs(i,visited);
		for(j=1;j<=N;j++){
			if (!visited[j]){
				flag=false;
				break;
			}
		}
		if(flag)sum++;
	}
	cout<<sum<<endl;	
	return 0;
}
