#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int rank[30050];
int fa[30050];

int find(int x);
void merge(int a,int b);

int main()
{
    int N,M,tmp1,tmp2,i,j,root;

    while(cin>>N>>M&&(N||M)){
        memset(rank,0,sizeof(rank));
        for(i=0;i<N;i++)
            fa[i]=i;
        for(i=1;i<=M;i++){
            scanf("%d",&tmp1);
            if(tmp1>0)
                scanf("%d",&root);
            for(j=1;j<tmp1;j++){
                scanf("%d",&tmp2);
                merge(root,tmp2);
            }
        }
        root=find(0);
        int ans=1;
        for(i=1;i<N;i++)
            if(find(i)==root)
                ans++;
        cout<<ans<<'\n';
    }
    return 0;
}

void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    else if(rank[a]>rank[b])
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
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
