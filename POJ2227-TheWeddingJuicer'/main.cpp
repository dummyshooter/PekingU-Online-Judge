#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct block
{
    short x,y;
    long height;
} BLOCK;

struct cmp{
    bool operator()(const BLOCK a, const BLOCK b) const
    {
        return a.height>b.height;
    }
};

const int trans[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
long height[305][305];
bool hash[305][305];
priority_queue <BLOCK,vector<BLOCK>,cmp> q;
long long sum=0;
int N,M;

void init();
void floodfill();

int main()
{
    int i,j;

    cin>>M>>N;

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            cin>>height[i][j];

    init();
    floodfill();

    cout<<sum<<endl;

    return 0;
}

void init()
{
    int i,j;
    BLOCK tmp;

    for(i=1;i<=N;i++){
        if(!hash[i][1]){
            tmp.height=height[i][1];
            tmp.x=i,tmp.y=1;
            q.push(tmp);
            hash[i][1]=true;
        }
        if(!hash[i][M]){
            tmp.height=height[i][M];
            tmp.x=i,tmp.y=M;
            q.push(tmp);
            hash[i][M]=true;
        }
    }

    for(j=1;j<=M;j++){
        if(!hash[1][j]){
            tmp.height=height[1][j];
            tmp.x=1,tmp.y=j;
            q.push(tmp);
            hash[1][j]=true;
        }
        if(!hash[N][j]){
            tmp.height=height[N][j];
            tmp.x=N,tmp.y=j;
            q.push(tmp);
            hash[N][j]=true;
        }
    }
    return;
}

void floodfill()
{
    BLOCK tmp,tmp_;

    while(!q.empty()){
        tmp=q.top();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=tmp.x+trans[i][0];
            int ty=tmp.y+trans[i][1];
            if(tx<=1||tx>=N||ty<=1||ty>=M||hash[tx][ty])
                continue;
            else if(height[tx][ty]>=tmp.height){
                tmp_.height=height[tx][ty];
                tmp_.x=tx;
                tmp_.y=ty;
                hash[tx][ty]=true;
                q.push(tmp_);
            }
            else{
                sum+=tmp.height-height[tx][ty];
                tmp_.height=tmp.height;
                tmp_.x=tx;
                tmp_.y=ty;
                hash[tx][ty]=true;
                q.push(tmp_);
            }
        }
    }
    return;
}

