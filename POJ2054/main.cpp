#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<double,int> PAIR;
priority_queue <PAIR,vector<PAIR> > q;
int fa[1005],c[1005],s[1005],ans[1005];
bool flag[1005];
double sp[1005];
int N,R,lc;

int find(int a);

int main()
{
	int i,a,b;

	while(cin>>N>>R&&(N||R)){
		memset(flag,false,sizeof(flag));
		for(i=1;i<=N;i++){
			scanf("%d",&c[i]);
			s[i]=1; sp[i]=(double(c[i])); ans[i]=c[i];
			q.push(make_pair(sp[i],i));
		}
		for(i=1;i<N;i++){
			scanf("%d%d",&a,&b);
			fa[b]=a;
		}
		fa[R]=R;
		while(!q.empty()){
			PAIR tmp=q.top(); q.pop();
			if(flag[tmp.second]||tmp.second==R||tmp.first!=sp[tmp.second])
				continue;
			flag[tmp.second]=true;
			int fa_=find(tmp.second);
			fa[tmp.second]=fa_;
			ans[fa_]+=c[tmp.second]*s[fa_]+ans[tmp.second];
			c[fa_]+=c[tmp.second]; s[fa_]+=s[tmp.second];
			sp[fa_]=(double)c[fa_]/(double)s[fa_];
			q.push(make_pair(sp[fa_],fa_));
		}
		printf("%d\n",ans[R]);
	}
	return 1;
}

int find(int a)
{
	if(a!=fa[a]&&flag[fa[a]])
		fa[a]=find(fa[a]);
	return fa[a];
}
