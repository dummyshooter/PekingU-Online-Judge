#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXIUM LINE*2
#define LINE 200000
#define INF -9999999
using namespace std;

int main()
{
	int N,left,right,i,j;
	long ts,tf;
	long dp[MAXIUM];

	cin>>N;
	for(i=0;i<MAXIUM;i++)
		dp[i]=INF;
	scanf("%ld%ld",&ts,&tf);
	dp[ts+LINE]=tf; dp[LINE]=0;
	if(ts<0){
		left=ts; right=0;
	}
	else{ left=0; right=ts;}
	for(i=1;i<N;i++){
		scanf("%ld%ld",&ts,&tf);
		if(ts<0){
			for(j=left;j<=right;j++)
				if(dp[j+LINE]>INF&&dp[j+LINE]+tf>dp[j+LINE+ts])
					dp[j+LINE+ts]=dp[j+LINE]+tf;
			left+=ts;
		}
		else{
			for(j=right;j>=left;j--)
				if(dp[j+LINE]>INF&&dp[j+LINE]+tf>dp[j+LINE+ts])
					dp[j+LINE+ts]=dp[j+LINE]+tf;
			right+=ts;
		}
	}
	long ans=0;
	for(i=0;i<=right;i++)
		if(dp[i+LINE]>=0&&dp[i+LINE]+i>ans)
			ans=dp[i+LINE]+i;
	printf("%ld\n",ans);

	return 1;
}
