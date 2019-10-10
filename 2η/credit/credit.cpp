#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int binarysearch(int *A,int s,int l,int h){
	int mid=(l+h)/2;
	if (s==A[mid]) return mid;
	else if (s>A[mid] && s<A[mid+1]) return (mid+1);
	else if (s>A[mid]) return binarysearch(A,s,mid+1,h);
	else if (s<A[mid]) return binarysearch(A,s,l,mid);
}


int main(){
	int N,*s,*r,i,*L1,*L2,*A,index,d=0,max=0;
	scanf("%d",&N);
	s=(int*)malloc(N*sizeof(int));
	r=(int*)malloc(N*sizeof(int));
	L1=(int*)malloc(N*sizeof(int));
	L2=(int*)malloc(N*sizeof(int));
	A=(int*)malloc(N*sizeof(int));
	for (i=0;i<N;i++) scanf("%d",&s[i]);
	A[0]=s[0];
	L1[0]=1;
	for (i=1;i<N;i++){
		if(s[i]>A[d]){
			d++;
			A[d]=s[i];
			L1[i]=d+1;
		}
		else if(s[i]<=A[0]){
			A[0]=s[i];
			L1[i]=1;
		}
		else{
			index=binarysearch(A,s[i],0,d);
			A[index]=s[i];
			L1[i]=index+1;
		}
	}
	for (i=1;i<N;i++){
		if(L1[i]<L1[i-1]) L1[i]=L1[i-1];
	}
	d=0;
	for (i=N-1;i>=0;i--){
		r[d] = (-1)*s[i];
		d++;
	}

	A[0]=r[0];
	L2[0]=1;
	d=0;
	for (i=1;i<N;i++){
		if(r[i]>A[d]){
			d++;
			A[d]=r[i];
			L2[i]=d+1;
		}
		else if(r[i]<=A[0]){
			A[0]=r[i];
			L2[i]=1;
		}
		else{
			index=binarysearch(A,r[i],0,d);
			A[index]=r[i];
			L2[i]=index+1;
		}
	}
	for (i=1;i<N;i++){
		if(L2[i]<L2[i-1]) L2[i]=L2[i-1];
	}
	max = L1[0]+L2[N-2];
	for (i=1;i<N;i++){
		if(max< L1[i]+L2[N-1-i]) max =L1[i]+L2[N-1-i];
	}
	cout<<max<<endl;
	return 0;
}
	
