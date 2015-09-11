#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 99999999
using namespace std;
int map[101][101];
int rmap[101][101];
bool s[101];
int dist[101];
int n,m;

bool dfs(int x);

int main()
{
    int i,j,k,x,y,min,id;

    while(scanf("%d%d",&n,&m)!=EOF){
        memset(rmap,0x7f7f,sizeof(rmap));
        for(i=0;i<n;i++)
            rmap[i][i]=0;
        memset(map,0,sizeof(map));
        memset(s,false,sizeof(s));
        while(scanf("%d%d",&x,&y)!=EOF){
            rmap[y][x]=1;
            map[x][y]=1;
        }
        for(i=0;i<n;i++)
            dist[i]=rmap[m][i];
        dist[m]=0;
        s[m]=1;
        for(i=1;i<n;i++){
            min=MAX;
            for(k=0;k<n;k++){
                if(!s[k]&&dist[k]<min){
                    min=dist[k];
                    j=k;
                }
            }
            s[j]=1;
            for(k=0;k<n;k++)
                if(!s[k]&&dist[j]+rmap[j][k]<dist[k])
                    dist[k]=dist[j]+rmap[j][k];
        }

        min=dist[0];

        id=0;
        for(i=0;i<n;i++){
            if(i==m)
                continue;
            for(j=0;j<n;j++)
                s[j]=0;
            s[i]=1;
            if(dfs(0)==0&&dist[i]<min){
                min=dist[i];
                id=i;
            }
        }
        printf("Put guards in room %d.\n",id);
    }
    return 0;
}

bool dfs(int x)
{
    if(x==m)
        return 1;
    s[x]=1;
    int i;
    for(i=0;i<n;i++){
        if(!s[i]&&map[x][i]){
            s[i]=1;
            if(dfs(i))
                return 1;
        }
    }
    return 0;
}
