#include <stdio.h>
#include <string.h>

char a[10050];
char b[1000050];
int next[10050];
int alen,blen;

void pre();
int kmp();

int main()
{
	int casenum;

	scanf("%d",&casenum);
	getchar();
	while(casenum-->0){
		gets(&a[1]);
		gets(&b[1]);
		alen=strlen(&a[1]);
		blen=strlen(&b[1]);
		pre();
		printf("%d\n",kmp());
	}
	return 0;
}

void pre()
{
	int i,j=0;
	next[1]=0;
	for(i=2;i<=alen;i++){
		while(j>0&&a[j+1]!=a[i])
			j=next[j];
		if(a[j+1]==a[i])
			j++;
		next[i]=j;
	}
}

int kmp()
{
	int i,j=0,count=0;
	for(i=1;i<=blen;i++){
		while(j>0&&a[j+1]!=b[i])
			j=next[j];
		if(a[j+1]==b[i])
			j++;
		if(j==alen){
			count++;
			j=next[j];
		}
	}
	return count;
}
