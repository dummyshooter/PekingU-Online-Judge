#include <iostream>
#include <cstring>

struct state{
	int x,y,step;
	char matrix[21][21];
};

int N,M;
state queue[100000];
char matrix[21][21];
short trans[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int front,rear;

int bfs();
void enqueue(int i,int j);
int dequeue();

using namespace std;
int main()
{
    int i,j;

    while(cin>>N>>M&&(N||M)){
        memset(queue,0,sizeof(queue));
        front=rear=0;
        for(i=1;i<=M;i++)
            for(j=1;j<=N;j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='2')
                    enqueue(i,j);
            }
		memcpy(queue[0].matrix,matrix,sizeof(matrix));
		queue[0].step=0;
		int ans=bfs();
		if(ans>10)
			ans=-1;
        cout<<ans<<'\n';
    }
    return 0;
}

int bfs()
{
    int tmp[2];
    int i,j;

    while(front<rear){
		int sign=dequeue();
		tmp[0]=queue[sign].x;
		tmp[1]=queue[sign].y;

		for(int a=0;a<4;a++){
			if(tmp[0]+trans[a][0]<1||tmp[0]+trans[a][0]>M||tmp[1]+trans[a][1]<1||tmp[1]+trans[a][1]>N)
				continue;
			if(queue[sign].matrix[tmp[0]+trans[a][0]][tmp[1]+trans[a][1]]=='1')
				continue;
			for(i=tmp[0]+trans[a][0],j=tmp[1]+trans[a][1];i>=1&&i<=M&&j>=1&&j<=N;){
				if(queue[sign].matrix[i][j]=='3')
					return queue[sign].step+1;
				if(queue[sign].matrix[i][j]=='1'){
					enqueue(i-trans[a][0],j-trans[a][1]);
					memcpy(queue[rear-1].matrix,queue[sign].matrix,sizeof(matrix));
					queue[rear-1].matrix[i][j]=0;
					queue[rear-1].step=queue[sign].step+1;
					break;
				}
				if(trans[a][0]==1)
					i++;
				else if(trans[a][0]==-1)
					i--;
				else if(trans[a][1]==1)
					j++;
				else
					j--;
			}
		}
    }
    return -1;
}

void enqueue(int i,int j)
{
    queue[rear].x=i;
    queue[rear].y=j;
	rear++;
}

int dequeue()
{
    front++;
    return front-1;
}


