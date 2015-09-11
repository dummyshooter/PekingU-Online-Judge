#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#define MAXIUMLINE 150050
#define MAXIUMVEX 30050
#define INF 1000000000
using namespace std;

typedef pair<int,int> PAIR;
int first[MAXIUMVEX],next[MAXIUMLINE],u[MAXIUMLINE],v[MAXIUMLINE],w[MAXIUMLINE],dis[MAXIUMVEX];
int lcount=0,N,M;
priority_queue <PAIR,vector<PAIR>,greater<PAIR> > q;

void add(int a,int b,int c);
void dijkstra();

int main()
{
	int a,b,c,i;

	scanf("%d%d",&N,&M);
	memset(first,-1,sizeof(first));
	for(i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	dijkstra();
	printf("%d\n",dis[N]);

	return 0;
}

void add(int a,int b,int c)
{
	u[lcount]=a;
	v[lcount]=b;
	w[lcount]=c;
	next[lcount]=first[a];
	first[a]=lcount;
	lcount++;

	return;
}

void dijkstra()
{
	bool used[MAXIUMVEX]={false};
	for(int i=1;i<=N;i++)
		dis[i]=INF;
	dis[1]=0;
	q.push(make_pair(0,1));

	while(!q.empty()){
		PAIR tmp=q.top();
		q.pop();
		int x=tmp.second;
		if(used[x])
			continue;
		used[x]=true;
		for(int ptr=first[x];ptr!=-1;ptr=next[ptr])
			if(dis[x]+w[ptr]<dis[v[ptr]]){
				dis[v[ptr]]=dis[x]+w[ptr];
				q.push(make_pair(dis[v[ptr]],v[ptr]));
			}
	}
	return;
}
