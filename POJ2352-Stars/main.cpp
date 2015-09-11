#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct segtree{
    int left,right,num;
} s[32000*4];
int level[32050];

void init(int root,int left,int right);
int query(int root,int x);
void add(int root,int left,int right);

int main()
{
    int i,N,tmpx,tmpy;

    cin>>N;
    memset(level,0,sizeof(level));
    init(1,0,32000);
    for(i=1;i<=N;i++){
        scanf("%d%d",&tmpx,&tmpy);
        level[query(1,tmpx)]++;
        add(1,tmpx,32000);
    }
    for(i=0;i<N;i++)
        printf("%d\n",level[i]);
    return 0;
}

void init(int root,int left,int right)
{
    s[root].left=left;
    s[root].right=right;
    s[root].num=0;

    if(left==right)
        return;
    else{
        int mid=(left+right)/2;
        init(2*root,left,mid);
        init(2*root+1,mid+1,right);
    }
    return;
}

int query(int root,int x)
{
    if(s[root].left==s[root].right)
        return s[root].num;
    int mid=(s[root].left+s[root].right)/2;
    if(x<=mid)
        return query(2*root,x)+s[root].num;
    else
        return query(2*root+1,x)+s[root].num;
}

void add(int root,int left,int right)
{
    if(s[root].left==left&&s[root].right==right){
        s[root].num++;
        return;
    }
    int mid=(s[root].left+s[root].right)/2;
    if(right<=mid)
        add(2*root,left,right);
    else if(left>mid)
        add(2*root+1,left,right);
    else{
        add(2*root,left,mid);
        add(2*root+1,mid+1,right);
    }
    return;
}
