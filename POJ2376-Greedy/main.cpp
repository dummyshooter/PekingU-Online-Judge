#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct PROP
{
	int start,end;
} prop;

bool cmp(prop a,prop b);

int main()
{
	int i,N,T,count=0;
	prop data[30000];

	cin>>N>>T;
	for(i=0;i<N;i++)
		scanf("%d%d",&data[i].start,&data[i].end);
	sort(data,data+N,cmp);
	int p1=0,tmpmax=1;
	i=0;
	if(data[0].start>1){
		cout<<"-1\n";
		return 0;
	}
	while(p1<T){
		for(;data[i].start<=p1+1&&i<N;i++)
			if(data[i].end>tmpmax)
				tmpmax=data[i].end;
		if(tmpmax==p1){
			cout<<"-1\n";
			return 0;
		}
		count++,p1=tmpmax;
	}
	cout<<count<<"\n";

	return 0;
}

bool cmp(prop a,prop b)
{
	if(a.start<=b.start)
		return true;
	else
		return false;
}
