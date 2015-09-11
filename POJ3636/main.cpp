#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 9999999
using namespace std;

typedef struct UNIT
{
	int w,h;
} unit;
unit s[20050];
int f[20050],ans,N;

bool cmp(unit a,unit b);
int bsearch(int a);

int main()
{
	int casenum,i;

	cin>>casenum;
	while(casenum--){
		cin>>N;
		for(i=0;i<N;i++)
			scanf("%d%d",&s[i].w,&s[i].h);
		sort(s,s+N,cmp);
		f[1]=s[0].h; f[0]=INF; ans=1;
		for(i=1;i<N;i++){
			if(s[i].h<=f[ans])
				f[++ans]=s[i].h;
			else{
				int pos=bsearch(s[i].h);
				f[pos+1]=s[i].h;
			}
		}
		printf("%d\n",ans);
	}
	return 1;
}

bool cmp(unit a,unit b)
{
	if(a.w<b.w)
		return true;
	else if(a.w==b.w&&a.h>b.h)
		return true;
	else
		return false;
}

int bsearch(int a)
{
	int left=0,right=ans,mid;
	mid=ans/2;
	while(mid!=right){
		if(a>f[mid])
			right=mid;
		else if(a<=f[mid])
			left=mid;
		if((left+right)%2==0)
			mid=(left+right)/2;
		else
			mid=(left+right)/2+1;
	}
	return mid-1;
}
