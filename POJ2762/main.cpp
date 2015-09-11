#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int v[6005],first[1005],next[6005],lc;
int v_[6005],first_[1005],next_[6005],deg[1005],lc_;
int index,top,sign;
int dfn[1005],low[1005],f[1005],stack[1005];
bool instack[1005],used[1005];

typedef pair<int,int> PAIR;
struct cmp{
	bool operator()(const PAIR &a,const PAIR &b){
		if(a.second>=b.second)
			return true;
		else
			return false;
	}
};
priority_queue <PAIR,vector<PAIR>,cmp> q;

void add(int a,int b);
void add_(int a,int b);
void tarjan(int m);

int main()
{
	int casenum,N,M,i,a,b;

	cin>>casenum;
	while(casenum--){
		lc=lc_=index=top=sign=0;
		cin>>N>>M;
		for(i=0;i<N;i++)
			first[i]=-1;
		for(i=0;i<M;i++){
			scanf("%d%d",&a,&b);
			add(a-1,b-1);
		}
		memset(dfn,0,sizeof(dfn));
		memset(instack,false,sizeof(instack));
		memset(deg,0,sizeof(deg));
		memset(used,false,sizeof(used));
		for(i=0;i<N;i++)
			if(!dfn[i])
				tarjan(i);
		for(i=0;i<sign;i++)
			first_[i]=-1;
		for(i=0;i<N;i++)
			for(int x=first[i];x!=-1;x=next[x])
				if(f[i]!=f[v[x]])
					add_(f[i],f[v[x]]);
		for(i=0;i<sign;i++)
			q.push(make_pair(i,deg[i]));
		bool flag=false;
		while(!q.empty()){
			PAIR tmp_1,tmp_2;
			tmp_1=q.top(); q.pop();
			if(used[tmp_1.first])
				continue;
			used[tmp_1.first]=true;
			if(q.empty())
				break;
			tmp_2=q.top();
			while(used[tmp_2.first]){
				q.pop();
				if(q.empty())
					goto MARK;
				tmp_2=q.top();
			}
			if(tmp_1.second==0&&tmp_2.second==0){
				flag=true;
				break;
			}
			for(int x=first_[tmp_1.first];x!=-1;x=next_[x]){
				deg[v_[x]]--;
				q.push(make_pair(v_[x],deg[v_[x]]));
			}
		}
MARK:   if(flag)
			printf("No\n");
		else
			printf("Yes\n");
		while(!q.empty())
			q.pop();
	}
	return 1;
}

void add(int a,int b)
{
	v[lc]=b;
	next[lc]=first[a];
	first[a]=lc;
	lc++;
}

void add_(int a,int b)
{
	for(int x=first_[a];x!=-1;x=next_[x])
		if(v_[x]==b)
			return;
	v_[lc_]=b;
	next_[lc_]=first_[a];
	first_[a]=lc_;
	deg[b]++;
	lc_++;
}

void tarjan(int m)
{
	int x;
	dfn[m]=low[m]=++index;
	stack[++top]=m;
	instack[m]=true;
	for(x=first[m];x!=-1;x=next[x]){
		if(!dfn[v[x]]){
			tarjan(v[x]);
			if(low[v[x]]<low[m])
				low[m]=low[v[x]];
		}
		else if(instack[v[x]]&&dfn[v[x]]<low[m])
			low[m]=dfn[v[x]];
	}
	if(dfn[m]==low[m]){
		do{
			x=stack[top--];
			instack[x]=false;
			f[x]=sign;
		} while(m!=x);
		sign++;
	}
	return;
}
