#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int pass[22][22][22][22];
int n,m;
int fa[22][22][2];
int al[22][22];
int inc[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int> > q;
stack<pair<int,int> > s;

void bfs(int ax,int ay,int bx,int by);

int main()
{
	int i,j;

	while(cin>>n>>m){
		memset(pass,0,sizeof(pass));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>al[i][j];
		int ax,ay,bx,by;
		while((cin>>ax>>ay>>bx>>by)&&(ax||ay||bx||by)){
			if(ax==bx){
				if(ay<by) for(i=ay;i<by;i++) pass[ax][i][bx][i+1]=1;
				else for(i=by;i<ay;i++) pass[ax][i+1][bx][i]=1;
			}
			else{
				if(ax<bx) for(i=ax;i<bx;i++) pass[i][ay][i+1][by]=1;
				else for(i=bx;i<ax;i++) pass[i+1][ay][i][by]=1;
			}
		}
		while((cin>>ax>>ay>>bx>>by)&&(ax||ay||bx||by)){
			if(ax==bx && ay==by) cout<<"To get from "<<ax<<'-'<<ay<<" to "<<bx<<'-'<<by<<", stay put!\n\n";
			else{
				bfs(ax,ay,bx,by);
				if(fa[bx][by][0] || fa[bx][by][1]){
					while(!s.empty()) s.pop();
					int tx=bx,ty=by;
					while(tx!=ax||ty!=ay){
						s.push(make_pair(tx,ty));
						int tmp=fa[tx][ty][0];
						ty=fa[tx][ty][1];
						tx=tmp;
					}
					cout<<ax<<'-'<<ay;
					while(!s.empty()){
						pair<int,int> tmp;
						tmp=s.top();
						s.pop();
						cout<<" to "<<tmp.first<<'-'<<tmp.second;
					}
					cout<<"\n\n";
				}
				else cout<<"There is no acceptable route from "<<ax<<'-'<<ay<<" to "<<bx<<'-'<<by<<".\n\n";
			}
		}
	}
	return 0;
}

void bfs(int ax,int ay,int bx,int by)
{
	memset(fa,0,sizeof(fa));
	while(!q.empty()) q.pop();
	q.push(make_pair(ax,ay));

	while(!q.empty()){
		pair<int,int> tmp;
		int tx,ty,px,py;
		tmp=q.front();
		q.pop();
		tx=tmp.first;
		ty=tmp.second;
		for(int i=0;i<4;i++){
			px=tx+inc[i][0];
			py=ty+inc[i][1];
			if(px<1||px>n||py<1||py>m)
				continue;
			if(pass[tx][ty][px][py]==0)
				continue;
			if(al[px][py]-al[tx][ty]>10)
				continue;
			if(fa[px][py][0] || fa[px][py][1])
				continue;
			fa[px][py][0]=tx;
			fa[px][py][1]=ty;
			if(px==bx && py==by) break;
			q.push(make_pair(px,py));
		}
		if(fa[bx][by][0] || fa[bx][by][1]) break;
	}
}
