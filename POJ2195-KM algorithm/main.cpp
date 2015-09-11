#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 999999
#define MAXIUM 200
#define ABS(x) (x>0?x:((-1)*(x)))
using namespace std;

typedef struct COORDIATE
{
	int x,y;
}
Coordiate;
int slk[MAXIUM],z[MAXIUM],fx[MAXIUM],fy[MAXIUM],lx[MAXIUM],ly[MAXIUM];
int matrix[MAXIUM][MAXIUM];
int flag,mcount,hcount;

bool dfs(int x);

int main()
{
	Coordiate m[105],h[105];
	int i,j,N,M;
	char tmp;

	while(scanf("%d%d",&N,&M)&&(N||M)){
		memset(fx,0,sizeof(fx));
		memset(fy,0,sizeof(fy));
		getchar();
		mcount=hcount=0;
		for(i=1;i<=N;i++){
			for(j=1;j<=M;j++){
				scanf("%c",&tmp);
				if(tmp=='m') m[mcount].x=i,m[mcount++].y=j;
				else if(tmp=='H') h[hcount].x=i,h[hcount++].y=j;
			}
			getchar();
		}
		for(i=0;i<mcount;i++)
			for(j=0;j<hcount;j++)
				matrix[i][j]=ABS(m[i].x-h[j].x)+ABS(m[i].y-h[j].y);
		for(j=0;j<hcount;j++){
			ly[j]=INF;
			for(i=0;i<mcount;i++)
				if(matrix[i][j]<ly[j])
					ly[j]=matrix[i][j];
		}
		for(i=0;i<mcount;i++) lx[i]=0,z[i]=-1;
		flag=0;
		for(i=0;i<mcount;i++){
			for(j=0;j<hcount;j++) slk[j]=INF;
			flag++;
			while(!dfs(i)){
				int d=INF;
				for(j=0;j<hcount;j++)
					if(fy[j]!=flag&&slk[j]<d)
						d=slk[j];
				for(j=0;j<mcount;j++)
					if(fx[j]==flag)
						lx[j]+=d;
				for(j=0;j<hcount;j++){
					slk[j]=INF;
					if(fy[j]==flag)
						ly[j]-=d;
				}
				flag++;
			}
		}
		int res=0;
		for(i=0;i<hcount;i++) res+=lx[i];
		for(i=0;i<mcount;i++) res+=ly[i];
		printf("%d\n",res);
	}

	return 0;
}

bool dfs(int x)
{
	int y,x0;

	fx[x]=flag;
	for(y=0;y<hcount;y++){
		if(lx[x]+ly[y]<matrix[x][y]){
			if(matrix[x][y]-lx[x]-ly[y]<slk[y])
				slk[y]=matrix[x][y]-lx[x]-ly[y];
		}
		else if(fy[y]!=flag){
			fy[y]=flag,x0=z[y];
			if(x0==-1||dfs(x0)){
				z[y]=x;
				return true;
			}
		}
	}
	return false;
}
