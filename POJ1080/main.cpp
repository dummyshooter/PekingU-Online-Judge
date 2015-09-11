#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[105],b[105];
int DEC[200]={0};
int value[5][5]={0,-3,-4,-2,-1,-3,5,-1,-2,-1,-4,-1,5,-3,-2,-2,-2,-3,5,-2,-1,-1,-2,-2,5};

int main()
{
	int casenum,len1,len2;
	int dp[105][105];

	DEC['A']=1,DEC['C']=2,DEC['G']=3,DEC['T']=4;
	cin>>casenum;
	while(casenum--){
		scanf("%d%s",&len1,&a[1]);
		scanf("%d%s",&len2,&b[1]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=len1;i++)
			dp[i][0]=dp[i-1][0]+value[DEC[a[i]]][0];
		for(int j=1;j<=len2;j++)
			dp[0][j]=dp[0][j-1]+value[0][DEC[b[j]]];
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
				dp[i][j]=max(dp[i-1][j-1]+value[DEC[a[i]]][DEC[b[j]]],max(dp[i][j-1]+value[0][DEC[b[j]]],dp[i-1][j]+value[DEC[a[i]]][0]));
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}

