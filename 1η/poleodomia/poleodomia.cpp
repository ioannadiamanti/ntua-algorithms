#include<iostream>
#include<stdlib.h>
using namespace std;

long long int calculator(long long int *p,long long int N);
int main(){
	long long int N,*h,i,min;
	cin >> N ;
	h = (long long int*)malloc (sizeof(long long int)*N);
	for (i=0;i<N;i++){
		cin >> h[i];
	}
	min = calculator(h,N);
	cout << min << endl;
	return 0;
}

long long int calculator(long long int *p,long long int N){
	long long int i,max=p[0],max_index=0,min,right=0,left=0;
	
	if(N==1) return max;

	for (i=0;i<N;i++){
		if(p[i]>max){
			max = p[i];
			max_index = i;
		}
	}
	if(max_index <N-1 and max_index > 0){
		right=calculator(p+max_index+1,N-max_index-1);
		left=calculator(p,max_index);
		if(left+(N-max_index)*max< right +(max_index+1)*max){
			min = left + (N-max_index)*max;
		}
		else{
			min = right + (max_index+1)*max;
		}
		return min;	
	}
	else if(max_index == 0){
		right=calculator(p+1,N-1);
		min = max+right;
		return  min;
	}
	else if(max_index == N-1 ){
		left = calculator(p,N-1);
		min = max+left;
		return min;
	}
		
	
}
