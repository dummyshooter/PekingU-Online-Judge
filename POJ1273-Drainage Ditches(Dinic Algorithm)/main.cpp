#include <iostream>
#include <cstring>
#define INF 0x7fffffff
using namespace std;

int map[205][205];
bool used[205];
int edge[205];
int deg[205];
int queue[205];
int stack[205];
int N,M;
int front,rear;
int top;

int dfs();
bool bfs();
int dinic();

int main()
{
    int i,tmpx,tmpy,tmpf;


    while(cin>>N>>M&&(N||M)){
        memset(map,0,sizeof(map));
        for(i=1;i<=N;i++){
            cin>>tmpx>>tmpy>>tmpf;
            map[tmpx][tmpy]+=tmpf;
        }
        cout<<dinic()<<'\n';
    }
    return 0;
}

int dinic()
{
    int flow=0;

    while(bfs()){
        int tmp=dfs();
        if(!tmp)
            break;
        flow+=tmp;
    }
    return flow;
}

bool bfs()
{
    int i;
    front=rear=0;
    memset(deg,-1,sizeof(deg));
    deg[1]=0;
    queue[rear++]=1;

    while(front<rear){
        int tmp=queue[front++];
        for(i=1;i<=M;i++)
            if(map[tmp][i]&&deg[i]==-1){
                deg[i]=deg[tmp]+1;
                if(i==M)
                    return true;
                queue[rear++]=i;
            }
    }
    return false;
}

int dfs()
{
    int i,j,flow=0;

    for(i=1;i<=M;i++)
	edge[i]=1;
    memset(used,false,sizeof(used));
    top=0;
    stack[top]=1;

    int ptr;
    while(top>=0){
        if(stack[top]==M){
            int tmpmin=INF;
            for(j=top;j>0;j--)
                tmpmin=min(tmpmin,map[stack[j-1]][stack[j]]);
            for(j=top;j>0;j--){
                map[stack[j-1]][stack[j]]-=tmpmin;
                map[stack[j]][stack[j-1]]+=tmpmin;
                if(map[stack[j-1]][stack[j]]==0)
                    ptr=j;
                }
            top=ptr-1;
            flow+=tmpmin;
        }
        else{
            bool flag=false;
            for(i=edge[stack[top]];i<=M;i++){
                edge[stack[top]]++;
                if(map[stack[top]][i]>0&&!used[i]&&(deg[i]==deg[stack[top]]+1)){
                    flag=true;
                    stack[++top]=i;
                    break;
                }
            }
            if(!flag){
                used[stack[top]]=true;
                top--;
                }
            }
        }
    return flow;
}
