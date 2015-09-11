#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int fa[50050];
int rank[50050];
bool hash[50050];

void merge(int a,int b);
int find(int x);

int main()
{
    int a,b,i,N,M,count=0;

    while(cin>>N>>M&&(N||M)){
        count++;
        memset(hash,false,sizeof(hash));
        memset(rank,0,sizeof(rank));
        for(i=1;i<=N;i++)
            fa[i]=i;
        for(i=1;i<=M;i++){
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int ans=0;
        for(i=1;i<=N;i++){
            a=find(i);
            if(!hash[a]){
                ans++;
                hash[a]=true;
            }
        }
        printf("Case %d: %d\n",count,ans);
    }
    return 0;
}

void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    else if(rank[a]>rank[b])     //启发式合并
        fa[b]=a;
    else if(rank[b]>rank[a])
        fa[a]=b;
    else{
        rank[a]++;
        fa[b]=a;
    }
    return;
}

int find(int x)
{
    if (x!= fa[x])
        fa[x]=find(fa[x]);     //压缩路径
    return fa[x];
}


