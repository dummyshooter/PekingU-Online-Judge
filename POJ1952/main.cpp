#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int N,i,j,s[5050];
	int dp[5050],n[5050];

	cin>>N;
	for(i=1;i<=N;i++)
		scanf("%d",&s[i]);
	int tmpmax=0;
	for(i=1;i<=N;i++){
		dp[i]=n[i]=1;
		for(j=i-1;j>0;j--){
			if(dp[j]+1>dp[i]&&s[j]>s[i]){
				dp[i]=dp[j]+1;
				n[i]=n[j];
			}
			else if(dp[j]+1==dp[i]&&s[j]>s[i])
				n[i]+=n[j];
			else if(s[j]==s[i]){
				if(dp[i]==1)
					n[i]=0;
				break;
			}
		}
		if(tmpmax<dp[i])
			tmpmax=dp[i];
	}
	int ans=0;
	for(i=1;i<=N;i++){
		if(dp[i]==tmpmax)
			ans+=n[i];
	}
	printf("%d %d\n",tmpmax,ans);

	return 0;
}
