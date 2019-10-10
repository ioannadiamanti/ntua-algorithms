#include<stdio.h>

int main(int argc,char** argv){
	FILE *fp1;
	FILE *fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");
	char i='a';
	char j;
	int res=1;
	int line=1;
	while(i!=EOF){
		i=fgetc(fp1);
		j=fgetc(fp2);
		if(i=='\n')line++;
		if(i!=j){
			res=0;
			printf("%d\n",line);
			break;
		}
	}
	if(res)printf("YES\n");
	else printf("NO\n");
}
