#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct LINE
{
	int x,y;
	int dist;
} line;

int anc[105];
int rank[105];

bool cmp(line a,line b);
int find(int x);
void unit(int x,int y);

int main()
{
	int N,Q,i,j;
	int lcount=0,sum=0;
	int map[105][105];
	line seq[10050];

	cin>>N;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&map[i][j]);
	for(i=0;i<N;i++)
		anc[i]=i,rank[i]=0;
	cin>>Q;
	int a,b;
	for(i=0;i<Q;i++){
		scanf("%d%d",&a,&b);
		unit(a-1,b-1);
		map[a-1][b-1]=0,map[b-1][a-1]=0;
	}
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(map[i][j]){
				seq[lcount].x=i,seq[lcount].y=j;
				seq[lcount++].dist=map[i][j];
			}
	sort(seq,seq+lcount,cmp);
	for(i=0;i<lcount;i++)
		if(find(seq[i].x)!=find(seq[i].y)){
			unit(seq[i].x,seq[i].y);
			sum+=seq[i].dist;
		}
	cout<<sum<<'\n';

	return 0;
}

bool cmp(line a,line b)
{
	if(a.dist<=b.dist)
		return true;
	else
		return false;
}

int find(int x)
{
	if(anc[x]!=x)
		anc[x]=find(anc[x]);
	return anc[x];
}

void unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	if (rank[x] > rank[y]) {
		anc[y] = x;
	}
	else{
		if (rank[x] == rank[y]){
			rank[y]++;
		}
		anc[x] = y;
	}
}

