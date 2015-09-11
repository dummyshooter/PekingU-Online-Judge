#include <iostream>
#include <cstdio>
#include <cstring>
#define LINE 15
using namespace std;

int main()
{
	int casenum,N,i,j,k;
	long dp[15][30][30];

	cin>>casenum;
	while(casenum--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&N);
		dp[0][LINE][LINE]=1;
		for(i=1;i<=N;i++)
			for(j=0;j<30;j++)
				for(k=0;k<30;k++)
					dp[i][j][k]=dp[i-1][j][k-1]+dp[i-1][j][k+1]+dp[i-1][j-1][k-1]+dp[i-1][j-1][k]+dp[i-1][j+1][k]+dp[i-1][j+1][k+1];
		printf("%ld\n",dp[N][LINE][LINE]);
	}
	return 1;
}
