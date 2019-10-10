#include<iostream>
#include<stdlib.h>
#include<cstdio>

using namespace std;

struct somatidia{
	int t,v,num;
	bool in_race;
};
void calculator(double tmin,double tmax,struct somatidia *a,struct somatidia *b,int N,int j,int L);
int *numa,*numb;
double tmid;
int readint() {
	int n = 0;
	char c = getchar_unlocked();
	while ( !( '0' <= c && c <= '9' ) ) {
		c = getchar_unlocked();
	}
	while ( '0' <= c && c <= '9' ) {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int main(){
	int N,L,K,i,j;
	double tmax,tmin;
	struct somatidia *a,*b;	
	N=readint();
	L=readint();
	K=readint();
	a = (struct somatidia *)malloc(N*sizeof(struct somatidia));
	b = (struct somatidia *)malloc(N*sizeof(struct somatidia));
	numa = (int*)malloc(K*sizeof(int));
	numb = (int*)malloc(K*sizeof(int));
	a[0].t=readint();
	a[0].v=readint();
	a[0].num = 1;
	a[0].in_race=true;
	tmin = a[0].t;
	tmax = L/a[0].v + a[0].t;
	for(i=1;i<N;i++){
		a[i].t=readint();
		a[i].v=readint();
		a[i].num = i+1; 
		a[i].in_race=true;
		if(L/a[i].v + a[i].t > tmax) tmax = L/a[i].v + a[i].t;
	} 
	for(i=0;i<N;i++){
		b[i].t=readint();
		b[i].v=readint();
		b[i].num = i+1;
		b[i].in_race=true;
		if(L/b[i].v + b[i].t > tmax) tmax = L/b[i].v + b[i].t;
	}
	for(i=0;i<K;i++) {
		calculator(tmin,tmax,a,b,N,i,L);
		cout<< numa[i] << " " << numb[i]<<endl;
		tmin=tmid;
	}
	return 0;
}

void calculator(double tmin,double tmax,struct somatidia *a,struct somatidia *b,int N,int j,int L){
	double maxa=0.0,maxb=0.0,temp;
	int i;
	bool flag1=false,flag2=false;
	tmid = (tmin+tmax)/2.0;
	for (i=0;i<N;i++){
		if(a[i].in_race){
			temp = (tmid-a[i].t)*a[i].v;
			if(temp > maxa){
				maxa = temp;
				numa[j] = a[i].num;
			}
			if(temp<0)flag1=true;
		}
		if(b[i].in_race){
			temp = (tmid-b[i].t)*b[i].v;
			if(temp > maxb){
				maxb = temp;
				numb[j] = b[i].num;
			}
			if(temp<0) flag2=true;
		}
		if(flag1 and flag2)break;		
	}
	if(maxa+maxb >= L-0.5 and maxa+maxb <=L+0.5){
		a[numa[j]-1].in_race=false;
		b[numb[j]-1].in_race=false;
	}
	else if(maxa + maxb >L+0.5) calculator(tmin,tmid,a,b,N,j,L);
	else calculator(tmid,tmax,a,b,N,j,L);	
}
