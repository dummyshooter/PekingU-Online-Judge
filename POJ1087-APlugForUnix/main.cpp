#include <iostream>
#include <cstdio>
#include <cstring>
#define des 1000
#define plug 800
#define INF 999999
using namespace std;

int matrix[1005][1005];
int cnet[1005][1005];
bool used[1005];
int path[1005];
int N,M,K;

int Ford_Fulkerson();
bool dfs(int s);

int main()
{
    int i,j;
    char buff1[25],buff2[25];
    char st[1005][25];

    memset(matrix,0,sizeof(matrix));

    cin>>N;
    for(i=1;i<=N;i++)
        cin>>st[i];
    cin>>M;
    for(i=1;i<=M;i++)
		cin>>buff1>>st[i+plug];
	int count=N;
    for(i=1;i<=M;i++){
		int sign=0;
        for(j=1;j<=count;j++)
            if(!strcmp(st[i+plug],st[j])){
                matrix[i+plug][j]=1;
				sign=1;
                break;
            }
		if(!sign){
			strcpy(st[++count],st[i+plug]);
			matrix[i+plug][count]=1;
		}
	}
    cin>>K;
    for(int k=1;k<=K;k++){
		cin>>buff1>>buff2;
        for(i=1;i<=count;i++)
            for(j=1;j<=count;j++)
                if((!strcmp(st[i],buff1))&&(!strcmp(st[j],buff2)))
                    matrix[i][j]=INF;
    }

	for(i=1;i<=M;i++)
		matrix[0][i+plug]=1;
	for(i=1;i<=N;i++)
		matrix[i][des]=1;

	int tmp=Ford_Fulkerson();
	cout<<(M-tmp)<<'\n';

    return 0;
}

int Ford_Fulkerson()
{
	int tmpmin=INF,i,p;

	memcpy(cnet,matrix,sizeof(matrix));
	while(dfs(0)){
		for(p=des;p!=0;p=path[p])
			if(cnet[path[p]][p]<tmpmin)
				tmpmin=cnet[path[p]][p];
		for(p=des;p!=0;p=path[p]){
			cnet[path[p]][p]-=tmpmin;
			cnet[p][path[p]]+=tmpmin;
		}
		memset(used,false,sizeof(used));
	}
	int ans=0;
	for(i=1;i<=M;i++)
		ans+=matrix[0][i+plug]-cnet[0][i+plug];
	return ans;
}

bool dfs(int s)
{
	int i;

	used[s]=true;
	for(i=1;i<=des;i++)
		if(cnet[s][i]&&!used[i]){
			path[i]=s;
			used[i]=true;
			if(i==des)
				return true;
			if(dfs(i))
				return true;
		}
	return false;
}


