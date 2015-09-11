#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 9999999
#define MNLINE 500000
#define MNVEX 20050

using namespace std;

int N,M,lc=0;
int u[MNLINE],v[MNLINE],w[MNLINE],next[MNLINE],first[MNVEX];
int queue[MNVEX*4],stack[MNVEX*4],deg[MNVEX],father[MNVEX];
bool used[MNVEX];

void add(int a,int b,int c);
int dinic();
bool bfs();
int dfs();

int main()
{
	int tmp_a,tmp_b,tmp_c,i;

	memset(first,-1,sizeof(first));
	cin>>N>>M;
	for(i=1;i<=N;i++){
		scanf("%d%d",&tmp_a,&tmp_b);
		add(0,i,tmp_a);
		add(i,0,0);
		add(i,N+1,tmp_b);
		add(N+1,i,0);
	}
	for(i=1;i<=M;i++){
		scanf("%d%d%d",&tmp_a,&tmp_b,&tmp_c);
		add(tmp_a,tmp_b,tmp_c);
		add(tmp_b,tmp_a,tmp_c);
	}
	printf("%d\n",dinic());

	return 0;
}

void add(int a,int b,int c)
{
	u[lc]=a,v[lc]=b,w[lc]=c;
	next[lc]=first[a];
	first[a]=lc;
	lc++;
}

int dinic()
{
	int flow=0;

	while(bfs()){
		int tmp=dfs();
		if(tmp==0)
			break;
		flow+=tmp;
	}
	return flow;
}

bool bfs()
{
	int front=0,rear=0;
	memset(deg,-1,sizeof(deg));
	deg[0]=0;
	queue[rear]=0;
	rear=(rear+1)%MNVEX;

	while(front!=rear){
		int tmp=queue[front];
		front=(front+1)%MNVEX;
		for(int i=first[tmp];i!=-1;i=next[i]){
			if(deg[v[i]]==-1)
				deg[v[i]]=deg[tmp]+1;
			if(v[i]==N+1)
				return true;
			queue[rear]=v[i];
			rear=(rear+1)%MNVEX;
		}
	}

	return false;
}

int dfs()
{
	int i,flow=0,top=0,ptr_;

	memset(used,false,sizeof(used));
	stack[top++]=0,father[0]=0;
	int ptr=0;
	while(top){
		while(ptr!=N+1&&top){
			for(i=first[ptr];i!=-1;i=next[i])
				if(deg[v[i]]==deg[ptr]+1&&w[i]>0&&!used[v[i]]){
					stack[top++]=(ptr=v[i]);
					father[ptr]=i;
					break;
				}
			if(i==-1){
				used[ptr]=true;
				top--;
				if(top) ptr=stack[top-1];
			}
		}
		if(ptr==N+1){
			int tmpmin=INF;
			while(ptr){
				ptr=father[ptr];
				if(w[ptr]<tmpmin)
					tmpmin=w[ptr];
				ptr=u[ptr];
			}
			ptr=N+1;
			while(ptr){
				ptr=father[ptr];
				w[ptr]-=tmpmin;
				if(u[ptr-1]==v[ptr]&&v[ptr-1]==u[ptr])
					w[ptr-1]+=tmpmin;
				else
					w[ptr+1]+=tmpmin;
				if(w[ptr]==0)
					ptr_=u[ptr];
				ptr=u[ptr];
			}
			while(top&&stack[top-1]!=ptr_) top--;
			if(top)
				ptr= stack[top-1];
			flow+=tmpmin;
		}
	}

	return flow;
}
