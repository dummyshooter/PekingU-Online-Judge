#include <iostream>
#include <cstdio>
using namespace std;

int ans,N,K,map[10][10];
bool tabu[10];

void dfs(int n,int k);

int main()
{
	int i,j;
	char tmp;

	while(cin>>N>>K){
		ans=0;
		if(N==-1&&K==-1)
			break;
		getchar();
		for(i=0;i<N;i++){
			tabu[i]=false;
			for(j=0;j<N;j++){
				map[i][j]=0;
				scanf("%c",&tmp);
				if(tmp=='#')
					map[i][j]=1;
			}
			getchar();
		}
		dfs(0,K);
		printf("%d\n",ans);
	}
	return 1;
}

void dfs(int n,int k)
{
	if(k==0){
		ans++;
		return;
	}
	if(n==N)
		return;
	for(int i=0;i<N;i++)
		if(!tabu[i]&&map[n][i]){
			tabu[i]=true;
			dfs(n+1,k-1);
			tabu[i]=false;
		}
	dfs(n+1,k);
	return;
}
