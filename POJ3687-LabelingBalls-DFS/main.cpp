#include <iostream>
#include <string.h>
#define MAXIUM  205

using namespace std;

int dfs(int,int);

int AdjList[MAXIUM][MAXIUM];
int color[MAXIUM]={0};
int starttime[MAXIUM];
int endtime[MAXIUM];
int time;


int main()
{
    int casenum;
    int N,M;
    int x,y;
    int i,j;
    int error=-1;

    cin>>casenum;

    while(casenum-->0){
		int sign=0;
        time=0;
        memset(AdjList,0,sizeof(int)*MAXIUM*MAXIUM+1);
		memset(color,0,sizeof(int)*MAXIUM+1);
		memset(endtime,0,sizeof(int)*MAXIUM+1);
        cin>>N>>M;
        for(i=1;i<=M;i++){
            cin>>x>>y;
            AdjList[y][x]=1;
        }

        for(i=1;i<=N;i++)
            if(!color[i])
                if(!dfs(i,N)){
                    cout<<error<<endl;
                    sign=1;
					break;
                }

		if(sign)
			continue;

        int seq[MAXIUM]={0};
        for(i=1;i<=N;i++)
            seq[i]=i;

        int tmp=0,tmp_=0;

        for(i=2;i<=N;i++){
            tmp=endtime[i];
            tmp_=seq[i];
            for(j=i;j>1&&endtime[j-1]>tmp;j--){
                seq[j]=seq[j-1];
                endtime[j]=endtime[j-1];
                }
            seq[j]=tmp_;
            endtime[j]=tmp;
        }

        for(i=1;i<=N-1;i++)
            cout<<seq[i]<<' ';
		cout<<seq[N];
        cout<<"\n";
    }

    return 0;
}

int dfs(int i,int N){
    color[i]=1;
    time++;
    starttime[i]=time;
    for(int j=1;j<=N;j++)
        if(AdjList[i][j]){
            if(color[j]==1)
                return 0;
            else if(color[j]==0){
                if(!dfs(j,N))
                    return 0;
            }
        }
    color[i]=2;
    time++;
    endtime[i]=time;

    return 1;
}


