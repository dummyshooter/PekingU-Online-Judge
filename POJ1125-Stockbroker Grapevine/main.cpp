#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int dist[10000][10000];
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=10000;
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
}

void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k]&&dist[k][j])
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
    int a,b,result,sum,k,maxn;
    while(cin>>n&&n){
        init();
        result=1000000;
        for(int i=1;i<=n;i++){
            cin>>m;
            for(int j=1;j<=m;j++){
                scanf("%d%d",&a,&b);
                dist[i][a]=b;
            }
        }
        floyd();
        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=1;j<=n;j++)
                sum+=dist[i][j];
            if(result>sum){
                result=sum;
                k=i;
            }
        }
        if(result>=1000000)
            cout<<"disjoint\n";
        else{
            maxn=dist[k][1];
            for(int i=2;i<=n;i++)
            if(maxn<dist[k][i])
                maxn=dist[k][i];
            printf("%d %d\n",k,maxn);
        }
    }
    return 0;
}
