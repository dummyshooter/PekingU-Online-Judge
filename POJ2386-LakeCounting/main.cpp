#include <iostream>
#include <cstdio>

int N,M;
int count=0;
bool list[105][105];
bool used[105][105];
const short trans[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void dfs(int i,int j);

using namespace std;
int main()
{
    char tmp;
    int i,j;

    cin>>N>>M;
    getchar();
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++)
            if((tmp=getchar())=='W')
                list[i][j]=true;
        getchar();
    }

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(!used[i][j]){
                dfs(i,j);
                count++;
            }

    cout<<count<<'\n';
    return 0;
}

void dfs(int i,int j)
{
    used[i][j]=true;
    for(int a=0;a<8;a++){
        int x=i+trans[a][0];
        int y=i+trans[a][1];
        if(x<=N&&x>0&&y<=M&&y>0&&list[x][y]&&!used[x][y])
            dfs(x,y);
    }
    return ;
}
