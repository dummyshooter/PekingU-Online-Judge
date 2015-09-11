#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N,i,s[150050];
	int dp[150050][2];

	cin>>N;
	for(i=1;i<=N;i++)
		scanf("%d",&s[i]);
	dp[0][0]=dp[0][1]=0;
	for(i=1;i<=N;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+s[i]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][0]-s[i]);
	}
	printf("%d\n",max(dp[N][0],dp[N][1]));

	return 0;
}
