#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 10000
using namespace std;

int N,M;
const int trans[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool matrix[80][80];
bool used[80][80];
short queue[SIZE][2];
int front,rear;

int bfs(int sx,int sy,int ex,int ey);
void enqueue(int x,int y);
void dequeue(int tmp[]);

int main()
{
    int i,j;

    int count1=0;
    while(cin>>M>>N&&(N||M)){
        getchar();
        count1++;
        memset(matrix,false,sizeof(matrix));
        int s[2],e[2];
        char tmp;
        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++)
               if((tmp=getchar())&&(tmp=='X'))
                    matrix[i][j]=true;
			getchar();
		}
		printf("Board #%d:\n",count1);
        int count2=0;
        while(cin>>s[1]>>s[0]>>e[1]>>e[0]&&(s[1]||s[0]||e[1]||e[1])){
            memset(used,false,sizeof(used));
            count2++;
            int ans=bfs(s[0],s[1],e[0],e[1]);
            printf("Pair %d: ",count2);
            if(ans==-1)
                cout<<"impossible.\n";
            else
                cout<<ans<<" segments.\n";
        }
        cout<<'\n';
    }
    return 0;
}

int bfs(int sx,int sy,int ex,int ey)
{
    int dp[80][80];
    front=rear=0;
    memset(dp,0,sizeof(dp));

    enqueue(sx,sy);

    while(front!=rear){
        int tmp[2];
        dequeue(tmp);
        for(int i=0;i<4;i++)
            for(int j=1;j<=max(N,M)+1;j++){
                int tmpx=tmp[0]+trans[i][0]*j;
                int tmpy=tmp[1]+trans[i][1]*j;
                if(tmpx<0||tmpx>(N+1)||tmpy<0||tmpy>(M+1))
                    break;
                if(tmpx==ex&&tmpy==ey)
                    return dp[tmp[0]][tmp[1]]+1;
				if(matrix[tmpx][tmpy])
					break;
                if(!used[tmpx][tmpy]){
                    dp[tmpx][tmpy]=dp[tmp[0]][tmp[1]]+1;
                    used[tmpx][tmpy]=true;
                    enqueue(tmpx,tmpy);
                }
            }
    }
    return -1;
}

void enqueue(int x,int y)
{
    queue[rear][0]=x;
    queue[rear][1]=y;
    rear=(rear+1)%SIZE;
}

void dequeue(int tmp[])
{
    tmp[0]=queue[front][0];
    tmp[1]=queue[front][1];
    front=(front+1)%SIZE;
}
