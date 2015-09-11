#include <iostream>
#define NIL 99999999

int height[105][105];
int dp[105][105];
int R,C;

using namespace std;

int dfs(int,int);

int main()
{
    int max=0,tmp,m,i,j;

    cin>>R>>C;
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            cin>>height[i][j];

    for(m=0;m<=R+1;m++){          //重要初始化
        height[m][0]=NIL;
        height[m][C+1]=NIL;
    }
    for(m=0;m<=R+1;m++){
        height[0][m]=NIL;
        height[R+1][m]=NIL;
    }

    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            if((tmp=dfs(i,j))>max)
                max=tmp;

    cout<<max<<"\n"<<endl;
    return 0;
}

int dfs(int i,int j)
{
    int tmp[4]={0};
    int tmpmax=0;

    if(dp[i][j])
        return dp[i][j];
    if(height[i][j+1]<height[i][j])
        tmp[0]=dfs(i,j+1);
    if(height[i+1][j]<height[i][j])
        tmp[1]=dfs(i+1,j);
    if(height[i][j-1]<height[i][j])
        tmp[2]=dfs(i,j-1);
    if(height[i-1][j]<height[i][j])
        tmp[3]=dfs(i-1,j);

    for(int m=0;m<4;m++)
        if(tmp[m]>tmpmax)
            tmpmax=tmp[m];
    dp[i][j]=++tmpmax;
    return tmpmax;
}
