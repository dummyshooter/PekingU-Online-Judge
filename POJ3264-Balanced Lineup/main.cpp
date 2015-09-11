#include <iostream>
#include <cstdio>
#define MAXIUM 50050
#define INF 99999999
using namespace std;

void init(int root,int left,int right);
void add(int root,int pos,int height);
int querymax(int root,int left,int right);
int querymin(int root,int left,int right);

struct segtree{
    int left,right;
    int min,max;
} st[MAXIUM*4];

int main()
{
    int N,Q,h,i,tmp1,tmp2,l,r;

    cin>>N>>Q;
    init(1,1,N);
    for(i=1;i<=N;i++){
        scanf("%d",&h);
        add(1,i,h);
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d",&l,&r);
        tmp1=querymax(1,l,r);
        tmp2=querymin(1,l,r);
        printf("%d\n",tmp1-tmp2);
    }
    return 0;
}

void init(int root,int left,int right)
{
    st[root].left=left;
    st[root].right=right;
    st[root].min=INF;
    st[root].max=0;

    if(left==right)
        return;
    else{
        int mid=(left+right)/2;
        init(root*2,left,mid);
        init(root*2+1,mid+1,right);
    }
    return;
}

void add(int root,int pos,int height)
{
    if(height>st[root].max)
        st[root].max=height;
    if(height<st[root].min)
        st[root].min=height;
    if(st[root].left==st[root].right)
        return;
    else{
        int mid=(st[root].left+st[root].right)/2;
        if(pos<=mid)
            add(root*2,pos,height);
        else
            add(root*2+1,pos,height);
    }
    return;
}

int querymax(int root,int left,int right)
{
    if(st[root].left==left&&st[root].right==right)
        return st[root].max;
    int mid=(st[root].left+st[root].right)/2;
    if(right<=mid)
        return querymax(root*2,left,right);
    else if(left>mid)
        return querymax(root*2+1,left,right);
    else{
        int tmp1=querymax(root*2,left,mid);
        int tmp2=querymax(root*2+1,mid+1,right);
        return max(tmp1,tmp2);
    }
}

int querymin(int root,int left,int right)
{
    if(st[root].left==left&&st[root].right==right)
        return st[root].min;
    int mid=(st[root].left+st[root].right)/2;
    if(right<=mid)
        return querymin(root*2,left,right);
    else if(left>mid)
        return querymin(root*2+1,left,right);
    else{
        int tmp1=querymin(root*2,left,mid);
        int tmp2=querymin(root*2+1,mid+1,right);
        return min(tmp1,tmp2);
    }
}
