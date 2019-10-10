#include<iostream>
#include<stdlib.h>
using namespace std;

long long int calculator(long long int *p,long long int N);
int main(){
	long long int N,*h,i;
	cin >> N ;
	h = (long long int*)malloc(sizeof(long long int)*N);
	for (i=0;i<N;i++){
		cin >> h[i];
	}
	cout << calculator(h,N) << endl;
	return 0;
}

long long int calculator(long long int *p,long long int N){
	long long int i,j,max=p[0],min,*right,*left;
	right = (long long int*)malloc(sizeof(long long int)*N);
	left = (long long int*)malloc(sizeof(long long int)*N);	
	left[0]=0;
	right[N-1]=0;
	for(i=1;i<N;i++){
		if(p[i]>=max){
			max=p[i];
			left[i] = max*i;
		}
		else if(p[i]>p[i-1]){
			left[i]=0;
			for(j=i-1;j>=0;j--){
				if(p[j]<p[i]){			
					left[i] += p[i];
				}
				else{
					left[i]+=left[j+1];
					break;
				}
			}
		}
		else left[i] = left[i-1]+p[i-1];
	}
	max = p[N-1];
	for(i=N-2;i>=0;i--){
		if(p[i]>=max){
			max=p[i];
			right[i] = max*(N-1-i);
		}
		else if(p[i]>p[i+1]){
			right[i]=0;
			for( j = i+1; j <N;j++){
				if(p[j]<p[i]){			
					right[i] += p[i];
				}
				else{
					right[i]+=right[j-1];
					break;
				}
			}
		}
		else right[i] = right[i+1]+p[i+1];
	}
	min = right[0]+left[0]+p[0];
	for (i=1;i<N;i++){
		if(right[i]+left[i]+p[i]<min) min = right[i]+left[i]+p[i];
	}
	return min;
}
