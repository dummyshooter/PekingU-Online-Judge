#include <iostream>
#include <cstdio>

int trans[4][2]={{0,1},{0,-1},{1,0},{1,-1}};
bool matrix[5][5];
bool used[5][5];
short queue[1000][2];
short path[5][5][2];
int front=0,rear=0;

void bfs();
void enqueue(int a,int b);
void dequeue(int a[2]);

using namespace std;
int main()
{
    int i,j;
    int tmp;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(cin>>tmp&&tmp)
                matrix[i][j]=true;

    enqueue(0,0);
    bfs();

    i=4,j=4;
	int stack[100][2],count=0;
    while(i||j){
		int tmp;
		stack[count][0]=i;
		stack[count++][1]=j;
        tmp=path[i][j][0];
        j=path[i][j][1];
		i=tmp;

    }
	stack[count][0]=0;
	stack[count][1]=0;

	for(i=count;i>=0;i--)
        printf("(%d, %d)\n",stack[i][0],stack[i][1]);

    return 0;
}

void bfs()
{
    int a[2];

    while(front<rear){
        dequeue(a);
        for(int i=0;i<4;i++){
            int x=a[0]+trans[i][0];
            int y=a[1]+trans[i][1];
            if(x<0||x>4||y<0||y>4)
                continue;
            if(!matrix[x][y]&&!used[x][y]){
                enqueue(x,y);
				used[x][y]=true;
                path[x][y][0]=a[0];
                path[x][y][1]=a[1];
            }
            if(x==4&&y==4)
                return;
        }
    }
}

void enqueue(int a,int b)
{
    queue[rear][0]=a;
    queue[rear++][1]=b;
}

void dequeue(int a[2])
{
    a[0]=queue[front][0];
    a[1]=queue[front++][1];
}

