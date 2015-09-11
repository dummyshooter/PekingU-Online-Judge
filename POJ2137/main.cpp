#include <iostream>
#include <cstdio>
#include <cmath>
#define DIST(a,b,c,d) sqrt((double)((a-c)*(a-c)+(b-d)*(b-d)))
#define INF 999999999.0
using namespace std;

int main()
{
	int N,i,j,k,m;
	int x[105][45],y[105][45],num[105];
	double dp[105][45],ans=INF;

	cin>>N;
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
		for(j=0;j<num[i];j++)
			scanf("%d%d",&x[i][j],&y[i][j]);
	}
	for(k=0;k<num[0];k++){
		for(i=0;i<num[1];i++)
			dp[1][i]=DIST(x[0][k],y[0][k],x[1][i],y[1][i]);
		for(i=2;i<N;i++)
			for(j=0;j<num[i];j++){
				dp[i][j]=INF;
				for(m=0;m<num[i-1];m++)
					dp[i][j]=min(dp[i][j],dp[i-1][m]+DIST(x[i-1][m],y[i-1][m],x[i][j],y[i][j]));
			}
		for(i=0;i<num[N-1];i++)
			if(dp[N-1][i]+DIST(x[0][k],y[0][k],x[N-1][i],y[N-1][i])<ans)
				ans=dp[N-1][i]+DIST(x[0][k],y[0][k],x[N-1][i],y[N-1][i]);
	}
	printf("%d\n",(int)(ans*100.0));
	return 1;
}
