#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1000050];
int next[1000050],len;
void kmp();

int main()
{
	while(scanf("%s",&str[1])&&str[1]!='.'){
		len=strlen(&str[1]);
		kmp();
		int ans=len-next[len];
		if(len%ans!=0)
			ans=len;
		printf("%d\n",len/ans);
	}
	return 1;
}

void kmp()
{
	int i,j=0;
	next[1]=0;
	for(i=2;i<=len;i++){
		while(j>0&&str[j+1]!=str[i])
			j=next[j];
		if(str[j+1]==str[i])
			j++;
		next[i]=j;
	}
	return;
}
