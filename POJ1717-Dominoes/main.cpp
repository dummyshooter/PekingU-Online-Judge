#include <iostream>
#include <windows.h>
#include <cstring>
#define MAXIUM 15000
#define NIL 999999
using namespace std;
int main()
{
    int N,i,j;
    int point[MAXIUM][2];
    int sum=0;
    int dp[6*MAXIUM];

    memset(point,0,sizeof(point));
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(i=1;i<=N;i++)
        cin>>point[i][0]>>point[i][1];

    dp[point[1][0]]=0;
	if(point[1][0]!=point[1][1])
		dp[point[1][1]]=1;
	else
		dp[point[1][0]]=0;
    sum+=point[1][0]+point[1][1];

    for(i=2;i<=N;i++){
        sum+=point[i][0]+point[i][1];
        for(j=sum;j>=0;j--){
			int tmp=NIL,sign=0;
            if(dp[j-point[i][0]]>=0&&(j-point[i][0])>=0){
				sign=1;
				tmp=dp[j-point[i][0]];
			}
            if(dp[j-point[i][1]]>=0&&(j-point[i][1])>=0){
				sign=1;
				if((dp[j-point[i][1]]+1)<tmp)
					tmp=dp[j-point[i][1]]+1;
			}
			if(!sign)
				tmp=-1;
			dp[j]=tmp;
        }
    }

	int sign=0;
    for(i=sum/2;i>=0;i--)
        if(dp[i]>=0)
			break;

	for(j=sum/2;j<=sum;j++)
		if(dp[j]>=0)
			break;

	if((sum-2*i)<(2*j-sum))
		cout<<dp[i];
	else if((sum-2*i)>(2*j-sum))
		cout<<dp[j];
	else
		cout<<min(dp[i],dp[j]);
	cout<<'\n';

    return 0;
}
