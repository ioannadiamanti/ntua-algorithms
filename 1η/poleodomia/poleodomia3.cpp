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
	long long int i,j,max=p[0],min,step,*r,*l,*right,*left;

	l = (long long int*)malloc (sizeof(long long int)*N);
	r = (long long int*)malloc (sizeof(long long int)*N);
	right = (long long int*)malloc (sizeof(long long int)*N);      
	left = (long long int*)malloc (sizeof(long long int)*N);   
	left[0]=0;   
	right[N-1]=0;  
	l[0]=1;  
	r[N-1]=1;  
	for (i = 1;i<N;i++){  
		if(p[i]<p[i-1]) l[i]=1;  
		else {  
			step=1;  
			while(step<=i && p[i]>=p[i-step]){  
				step+= l[i-step];  
			}  
			l[i]=step;  
		}  
	}  
     
	for (i = N-2;i>=0;i--){  
		if(p[i]<p[i+1]) r[i]=1;  
		else {  
			step=1;  
			while(step<N-i && p[i]>=p[i+step]){  
				step+= r[i+step];  
			}  
			r[i]=step;  
		}  
	}  
	for(i=0;i<N;i++){    
		if(p[i]>=max){    
			max=p[i];    
			left[i] = max*(i+1);    
		}    
		else{  
			left[i] = l[i]*p[i]+left[i-l[i]];     
		}    
	}    
	max = p[N-1];    
	for(i=N-1;i>=0;i--){    
		if(p[i]>=max){    
			max=p[i];    
			right[i] = max*(N-i);    
		}    
	        else{  
			right[i] = r[i]*p[i]+right[i+r[i]];  
		}    
	}    
	min = right[0]+left[0]-p[0];    
	for (i=1;i<N;i++){    
		if(right[i]+left[i]-p[i]<min) min = right[i]+left[i]-p[i];    
	}    
	return min;    
}
