#include <iostream>
#include <cstring>
#include <cstdio>
#define NIL 9999

typedef struct shipinfo
{
    int maxi,mini,maxj,minj;
}
si;

int N,M;
int trans[8][2]={{0,1},{1,0},{0,-1},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1}};
char matrix[1005][1005];
bool used[1005][1005];
si info;
int count;

void dfs(int i,int j);
bool judge();

using namespace std;
int main()
{
    int i,j;

    while(cin>>N>>M&&(N||M)){
		getchar();
        count=0;
        memset(used,false,sizeof(used));
        for(i=1;i<=N;i++)
			gets(&matrix[i][1]);

        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++)
                if(matrix[i][j]=='#'&&!used[i][j]){
                    info.maxi=-1;
					info.maxj=-1;
					info.mini=NIL;
					info.minj=NIL;
                    dfs(i,j);
                    if(!judge()){
                        count=-1;
                        break;
                    }
                    else
                        count++;
                }
            if(count==-1)
                break;
        }

        if(count==-1)
            cout<<"Bad placement.\n";
        else
            printf("There are %d ships.\n",count);
    }
    return 0;
}

void dfs(int i,int j)
{
    if(i>info.maxi)
        info.maxi=i;
    if(i<info.mini)
        info.mini=i;
    if(j>info.maxj)
        info.maxj=j;
    if(j<info.minj)
        info.minj=j;

    used[i][j]=true;
    for(int p=0;p<8;p++){
        int tmpx=i+trans[p][0];
        int tmpy=j+trans[p][1];
		if(tmpx<1||tmpx>N||tmpy<1||tmpy>M)
			continue;
        if(matrix[tmpx][tmpy]=='#'&&!used[tmpx][tmpy])
            dfs(tmpx,tmpy);
    }
    return;
}


bool judge()
{
    int i,j;
    for(i=info.mini;i<=info.maxi;i++)
        for(j=info.minj;j<=info.maxj;j++)
            if(matrix[i][j]!='#')
                return false;
    return true;
}
