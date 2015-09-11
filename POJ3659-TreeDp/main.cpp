#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 9999999
using namespace std;

int v[20005],next[20005],first[10005],degree[10005],lc=0;
int dp[10005][3];

void dfs(int x,int y);
void add(int a,int b);

int main()
{
	int N,i,a,b;
	cin>>N;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=N;i++){
		degree[i]=0;
		first[i]=-1;
	}
	for(i=1;i<N;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(0,1);
	printf("%d\n",min(dp[1][0],dp[1][1]));
	return 1;
}

void add(int a,int b)
{
	v[lc]=b;
	next[lc]=first[a];
	first[a]=lc++;
	degree[a]++;
}

void dfs(int x,int y)
{
	int i,tmpmin=INF,tmp_;
	bool flag=false;

	if(y!=1&&degree[y]==1){
		dp[y][0]=1;
		dp[y][1]=INF;
		dp[y][2]=0;
		return;
	}
	dp[y][0]=1;
	for(i=first[y];i!=-1;i=next[i]){
		if(v[i]==x)
			continue;
		dfs(y,v[i]);
		dp[y][0]+=min(dp[v[i]][0],min(dp[v[i]][1],dp[v[i]][2]));
		if(dp[v[i]][0]<=dp[v[i]][1]){
			dp[y][1]+=dp[v[i]][0];
			flag=true;
		}
		else{
			dp[y][1]+=dp[v[i]][1];
			if(dp[v[i]][0]<tmpmin){
				tmpmin=dp[v[i]][0];
				tmp_=dp[v[i]][1];
			}
		}
		dp[y][2]+=min(dp[v[i]][0],dp[v[i]][1]);
	}
	if(!flag)
		dp[y][1]+=tmpmin-tmp_;
	return;
}
