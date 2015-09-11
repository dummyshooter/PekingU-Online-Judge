#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct STICK
{
	int length,weight;
} stick;
stick s[5050];
int dp[5050];
bool cmp(stick a,stick b);

int main()
{
	int casenum,N,i,j;

	cin>>casenum;
	while(casenum--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d%d",&s[i].length,&s[i].weight);
		sort(s,s+N,cmp);
		for(i=1;i<N;i++)
			dp[i]=1;
		for(i=1;i<N;i++)
			for(j=0;j<i;j++)
				if(s[i].weight<s[j].weight&&dp[i]<dp[j]+1)
					dp[i]=dp[j]+1;
		int ans=0;
		for(i=0;i<N;i++)
			if(ans<dp[i])
				ans=dp[i];
		printf("%d\n",ans);
	}
	return 1;
}

bool cmp(stick a,stick b)
{
	if(a.length<b.length)
		return true;
	else if(a.length==b.length&&a.weight<b.weight)
		return true;
	else
		return false;
}
