#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[10050][11];
bool comp(int m,int n);
int cmp(const void *a,const void *b);

int main()
{
	int casenum,n,i;

	cin>>casenum;
	while(casenum--){
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		qsort(str[0],n,11*sizeof(char),cmp);
		bool flag=false;
		for(i=0;i<n;i++)
			if(comp(i,i+1)){
				flag=true;
				break;
			}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 1;
}

bool comp(int m,int n)
{
	int ptr=0;
	while(str[m][ptr]!='\0'){
		if(str[m][ptr]!=str[n][ptr])
			return false;
		ptr++;
	}
	return true;
}

int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
