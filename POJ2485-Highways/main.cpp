#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 9999999
using namespace std;

int matrix[505][505];
bool used[505];
int N;

int Prim();

int main()
{
    int casenum,i,j;

    cin>>casenum;
    while(casenum--){
        cin>>N;
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                scanf("%d",&matrix[i][j]);

        cout<<Prim()<<'\n';
    }
    return 0;
}

int Prim()
{
    int sum=0;
    memset(used,false,sizeof(used));
    used[1]=true;
    for(int i=1;i<N;i++)
    {
        int min=INF;
        int minnum=0;
        for(int j=1;j<=N;j++)
            if(used[j])
                for(int k=1;k<=N;k++)
                    if(!used[k]&&min>matrix[j][k]){
                        minnum=k;
                        min=matrix[j][k];
                    }
        used[minnum]=true;
        sum=sum>min?sum:min;
    }
    return sum;
}
