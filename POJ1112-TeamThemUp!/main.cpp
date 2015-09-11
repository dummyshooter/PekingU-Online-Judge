#include <iostream>
#include <cstring>
#define MAXIUM 150

int N;
int AdjMatrix[MAXIUM][MAXIUM];
int ConnectedSubgraphList[MAXIUM][2][MAXIUM];
int ConnectedSubgraphNum[MAXIUM][2];
int used[MAXIUM];
int color[MAXIUM];
int count=0;

int dfs(int v);
void add(int i,int p,int sign);

using namespace std;
int main()
{
    int i,j;
	int dp[MAXIUM][2*MAXIUM];
	int ConnectedSubgraphSel[MAXIUM];
	int outnum1=0,outnum2=0,tmp;

    cin>>N;
    for(i=1;i<=N;i++)
        while(cin>>j&&j)
            AdjMatrix[i][j]=1;

    for(i=1;i<N;i++)                   //矩阵反转
        for(j=i+1;j<=N;j++)
            if(AdjMatrix[i][j]&&AdjMatrix[j][i])
                AdjMatrix[i][j]=AdjMatrix[j][i]=0;
            else
                AdjMatrix[i][j]=AdjMatrix[j][i]=1;

    memset(color,-1,sizeof(color));
	memset(dp,0,sizeof(dp));
	memset(ConnectedSubgraphSel,0,sizeof(ConnectedSubgraphSel));

    for(i=1;i<=N;i++)
        if(!used[i]){
            color[i]=1;
			add(i,count+1,1);
			ConnectedSubgraphNum[++count][1]=1;
            if(!dfs(i)){
                cout<<"No solution\n";
                return 0;
			}
		}

	dp[0][MAXIUM]=1;

	for(i=1;i<=count;i++)
		for(j=0;j<=2*MAXIUM;j++)
			if(dp[i-1][j-ConnectedSubgraphNum[i][0]+ConnectedSubgraphNum[i][1]]||dp[i-1][j+ConnectedSubgraphNum[i][0]-ConnectedSubgraphNum[i][1]])
				dp[i][j]=1;

	for(j=MAXIUM;j<=2*MAXIUM;j++)
		if(dp[count][j])
			break;

	for(i=count-1;i>=0;i--)
		if(dp[i][j-ConnectedSubgraphNum[i+1][0]+ConnectedSubgraphNum[i+1][1]]){
			j=j-ConnectedSubgraphNum[i+1][0]+ConnectedSubgraphNum[i+1][1];
			ConnectedSubgraphSel[i+1]=0;
		}
		else if(dp[i][j+ConnectedSubgraphNum[i+1][0]-ConnectedSubgraphNum[i+1][1]]){
			j=j+ConnectedSubgraphNum[i+1][0]-ConnectedSubgraphNum[i+1][1];
			ConnectedSubgraphSel[i+1]=1;
		}

	for(i=1;i<=count;i++){
		tmp=1-ConnectedSubgraphSel[i];
		outnum1+=ConnectedSubgraphNum[i][tmp];
	}

	cout<<outnum1;

	for(i=1;i<=count;i++){
		tmp=1-ConnectedSubgraphSel[i];
		for(j=1;j<=ConnectedSubgraphNum[i][tmp];j++)
			cout<<' '<<ConnectedSubgraphList[i][tmp][j];
		if(i==count)
			cout<<"\n";
	}

	for(i=1;i<=count;i++){
		tmp=ConnectedSubgraphSel[i];
		outnum2+=ConnectedSubgraphNum[i][tmp];
	}

	cout<<outnum2;

	for(i=1;i<=count;i++){
		tmp=ConnectedSubgraphSel[i];
		for(j=1;j<=ConnectedSubgraphNum[i][tmp];j++)
			cout<<' '<<ConnectedSubgraphList[i][tmp][j];
		if(i==count)
			cout<<"\n";
	}

	return 0;
}

int dfs(int v)
{
    used[v]=1;
    for(int i=1;i<=N;i++)
        if(AdjMatrix[v][i]){
            if(color[v]==color[i])
                return 0;
            else if(!used[i]){
                if(color[v]){
                    color[i]=0;
                    add(i,count,0);
                    ConnectedSubgraphNum[count][0]++;
                }
                else{
                    color[i]=1;
                    add(i,count,1);
                    ConnectedSubgraphNum[count][1]++;
                }
                if(!dfs(i))
                    return 0;
            }
        }
    used[v]=2;
    return 1;
}

void add(int i,int p,int sign)
{
    ConnectedSubgraphList[p][sign][ConnectedSubgraphNum[p][sign]+1]=i;
}



