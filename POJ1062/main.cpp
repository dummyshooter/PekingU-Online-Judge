#include <iostream>
#include <cstring>
#define INF 99999999
using namespace std;

typedef struct GOOD
{
    int price;
    int level;
} Node;

int M,N;
Node status[105];
int map[105][105];
int dist[105];
bool used[105];

int dijkstra(int left,int right);

int main()
{
    int i,j,k;

    cin>>M>>N;
    memset(map,-1,sizeof(map));
    for(i=1;i<=N;i++){
        int tmp;
        cin>>status[i].price>>status[i].level>>tmp;
        for(j=1;j<=tmp;j++){
            int number,tmpd;
            cin>>number>>tmpd;
            map[i][number]=tmpd;
        }
    }

    for(i=1;i<=N;i++)
        map[i][0]=status[i].price;

    int stand=status[1].level;
	status[0].level=stand;
    int tmpmin=INF;
    for(k=stand-M;k<=stand;k++){
        int tmp=dijkstra(k,k+M);
        if(tmpmin>tmp)
            tmpmin=tmp;
    }

    cout<<tmpmin<<'\n';
    return 0;
}

int dijkstra(int left,int right)
{
    int i,j;

    memset(used,false,sizeof(used));
    memset(dist,0x7f7f,sizeof(dist));
    dist[1]=0;

    for(i=0;i<=N;i++){
        int tmpmin=INF;
        int tmp_=0;
        for(j=0;j<=N;j++)
            if(status[j].level>=left&&status[j].level<=right&&!used[j]&&dist[j]<tmpmin){
                tmpmin=dist[j];
                tmp_=j;
            }
		used[tmp_]=true;
        for(j=0;j<=N;j++)
            if(map[tmp_][j]>=0&&!used[j]&&status[j].level>=left&&status[j].level<=right)
                if(dist[j]>dist[tmp_]+map[tmp_][j])
                    dist[j]=dist[tmp_]+map[tmp_][j];
    }

    return dist[0];
}
