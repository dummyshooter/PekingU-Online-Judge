#include <iostream>
#include <cstring>

int queue[90000][2];
int hash[305][305];
int step[305][305];
int start[2],end[2];
int front,rear;

void enqueue(int a,int b);
void dequeue(int tmp[]);

using namespace std;
int main()
{
    int casenum;
    int N;
    int range[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

    cin>>casenum;
    while(casenum-->0){
        int sign=0;
        front=rear=0;
        memset(hash,0,sizeof(hash));
        memset(step,0,sizeof(step));
        cin>>N;
        cin>>start[0]>>start[1]>>end[0]>>end[1];
        if(start[0]==end[0]&&start[1]==end[1]){
            cout<<"0\n";
            continue;
        }
        enqueue(start[0],start[1]);
        step[start[0]][start[1]]=0;
        while(rear>front){
            int tmp[2];
            dequeue(tmp);
            for(int i=0;i<8;i++){
                int tmpx=tmp[0]+range[i][0],tmpy=tmp[1]+range[i][1];
                if(tmpx>=0&&tmpx<N&&tmpy>=0&&tmpy<N&&!hash[tmpx][tmpy]){
                    if(tmpx==end[0]&&tmpy==end[1]){
                        cout<<step[tmp[0]][tmp[1]]+1<<"\n";
                        sign=1;
                        break;
                    }
                    enqueue(tmpx,tmpy);
                    hash[tmpx][tmpy]=1;
                    step[tmpx][tmpy]=step[tmp[0]][tmp[1]]+1;
                }
            }
            if(sign)
                break;
        }
    }
        return 0;
}

void enqueue(int a,int b)
{
    queue[rear][0]=a;
    queue[rear][1]=b;
    rear++;
}

void dequeue(int tmp[])
{
    tmp[0]=queue[front][0];
    tmp[1]=queue[front][1];
    front++;
}
