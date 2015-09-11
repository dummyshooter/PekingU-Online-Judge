#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 999999

using namespace std;

int N,lcount=1;
int p[1005];
bool used[1005];
typedef struct AdjList
{
	int to,dist,next;
} List;

typedef struct VEX
{
	int sign,dist;
} Vex;

List list[300000];
Vex vex[1005];

struct cmp{
    bool operator()(const Vex a, const Vex b) const
    {
        return a.dist>b.dist;
    }
};
priority_queue <Vex,vector<Vex>,cmp> q;

void add(int x,int y,int dist);
void init();
void dijkstra();

int main()
{
	int T,i,j,k,tmp;

	cin>>T>>N;

	memset(p,0,sizeof(p));
	for(i=1;i<=T;i++){
		scanf("%d%d%d",&j,&k,&tmp);
		add(j,k,tmp);
		add(k,j,tmp);
	}

	init();
	dijkstra();
	cout<<vex[N].dist;

	return 0;
}

void add(int x,int y,int dist)
{
	if(p[x]==0){
		p[x]=lcount;
		list[lcount].to=y;
		list[lcount].next=0;
		list[lcount++].dist=dist;
		return;
	}

	int ptr=p[x];
	while(1){
		if(list[ptr].to==y){
			if(list[ptr].dist>dist)
				list[ptr].dist=dist;
			return;
		}
		if(list[ptr].next==0)
			break;
		ptr=list[ptr].next;
	}
	list[ptr].next=lcount;
	list[lcount].to=y;
	list[lcount].next=0;
	list[lcount++].dist=dist;

	return;
}

void init()
{
	memset(used,false,sizeof(used));

	for(int i=1;i<=N;i++){
		vex[i].sign=i;
		vex[i].dist=INF;
	}
	vex[1].dist=0;
	q.push(vex[1]);
}

void dijkstra()
{
	Vex tmp;

	while(!q.empty()){
		tmp=q.top(),q.pop();
		int x=tmp.sign;
		if(used[x])
			continue;
		used[x]=true;
		int ptr=p[x];
		for(;;){
			if(vex[x].dist+list[ptr].dist<vex[list[ptr].to].dist){
				vex[list[ptr].to].dist=vex[x].dist+list[ptr].dist;
				tmp.sign=list[ptr].to,tmp.dist=vex[list[ptr].to].dist;
				q.push(tmp);
			}
			if(list[ptr].next==0)
				break;
			ptr=list[ptr].next;
		}
	}
}
