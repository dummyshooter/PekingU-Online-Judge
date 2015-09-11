#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXIUM 1001
using namespace std;

typedef struct
{
	int num;
	int sign;
	int key;
} hashlist;

hashlist hash[MAXIUM];
bool judge[MAXIUM>>1];
bool stat[MAXIUM];
int fa[MAXIUM];
int find(int x);
bool solve(int i,int j,bool sign);
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);

int main()
{
    int len,M,i;
    char buff[5];

    scanf("%d%d",&len,&M);
    memset(stat,false,sizeof(stat));
    for(i=1;i<=M;i++){
        scanf("%d%d%s",&hash[i*2-1].key,&hash[i*2].key,buff);
        if(buff[0]=='e')
            judge[i]=false;
        else
            judge[i]=true;
        hash[i*2-1].num=i*2-1;
        hash[i*2].num=i*2;
    }
    qsort(&hash[1],2*M,sizeof(hashlist),cmp1);
    int count=0;
    for(i=1;i<=2*M;i++){
        if(hash[i].key==hash[i-1].key)
            hash[i].sign=count;
        else{
            count++;
            hash[i].sign=count;
        }
        fa[i]=i;
    }
    qsort(&hash[1],2*M,sizeof(hashlist),cmp2);
    for(i=1;i<=M;i++)
        if(!solve(hash[i*2-1].sign-1,hash[i*2].sign,judge[i]))
            break;
    cout<<i-1<<'\n';
    return 0;
}

bool solve(int i,int j,bool sign)
{
    int v1=find(i),v2=find(j);
    if(v1==v2){
        if((stat[i]^stat[j])!=sign)
            return false;
    }
    else{
        fa[v2]=v1;
        stat[v2]=sign^stat[i]^stat[j];
    }
    return true;
}

int find(int x)
{
    if(fa[x]==x)
        return x;
    int t=fa[x];
    fa[x]=find(fa[x]);
    stat[x]^=stat[t];
    return fa[x];
}

int cmp1(const void *a,const void *b)
{
	return (*(hashlist *)a).key>(*(hashlist *)b).key?1:-1;
}

int cmp2(const void *a,const void *b)
{
	return (*(hashlist *)a).num>(*(hashlist *)b).num?1:-1;
}
