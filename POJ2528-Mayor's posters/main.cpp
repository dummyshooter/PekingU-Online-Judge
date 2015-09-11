#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXIUM 20050
using namespace std;

struct segtree{
    int left,right;
    int sign;
} st[MAXIUM*4];

typedef struct HASHLIST{
	int num;
	int sign;
	int key;
} hashlist;

hashlist hash[MAXIUM];
bool check[10050];
int seg[MAXIUM];
int buff[MAXIUM];
int ans;

void init(int root,int left,int right);
void add(int root,int left,int right,int sign);
void query(int root,int left,int right);
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);

int main()
{
    int casenum,N,i;

    cin>>casenum;
    while(casenum--){
		memset(hash,0,sizeof(hash));
        memset(check,false,sizeof(check));
        scanf("%d",&N);
        init(1,1,2*N);
        for(i=1;i<=N;i++){
            scanf("%d%d",&hash[2*i-1].key,&hash[2*i].key);
			hash[2*i-1].num=2*i-1;
			hash[2*i].num=2*i;
		}
		qsort(&hash[1],2*N,sizeof(hashlist),cmp1);
		int count=0;
		for(i=1;i<=2*N;i++){
			if(hash[i].key==hash[i-1].key)
				hash[i].sign=count;
			else{
				count++;
				hash[i].sign=count;
			}
		}
		qsort(&hash[1],2*N,sizeof(hashlist),cmp2);
        for(i=1;i<=N;i++)
			add(1,hash[2*i-1].sign,hash[2*i].sign,i);
		ans=0;
		query(1,1,2*N);
        printf("%d\n",ans);
    }
    return 0;
}

void init(int root,int left,int right)
{
	int mid=(left+right)/2;

    st[root].left=left;
    st[root].right=right;
    st[root].sign=0;
    if(left<right){
        init(root*2,left,mid);
        init(root*2+1,mid+1,right);
    }
}

void add(int root,int left,int right,int sign)
{
	int mid=(st[root].left+st[root].right)/2;

    if(st[root].left==left&&st[root].right==right){
        st[root].sign=sign;
		return;
	}
    else{
		if(st[root].sign){
			add(root*2,st[root].left,mid,st[root].sign);
			add(root*2+1,mid+1,st[root].right,st[root].sign);
		}
		st[root].sign=0;
		if(right<=mid)
			add(root*2,left,right,sign);
		else if(left>mid)
			add(root*2+1,left,right,sign);
		else{
			add(root*2,left,mid,sign);
			add(root*2+1,mid+1,right,sign);
		}
	}
}

void query(int root,int left,int right)
{
	int mid=(st[root].left+st[root].right)/2;

    if(st[root].sign){
        if(!check[st[root].sign]){
            check[st[root].sign]=true;
            ans++;
        }
        return;
    }
	if(st[root].left==st[root].right)
		return;
    if(right<=mid)
        query(root*2,left,right);
    else if(left>mid)
        query(root*2+1,left,right);
    else{
        query(root*2,left,mid);
		query(root*2+1,mid+1,right);
	}
}


int cmp1(const void *a,const void *b)
{
	return (*(hashlist *)a).key>(*(hashlist *)b).key?1:-1;
}

int cmp2(const void *a,const void *b)
{
	return (*(hashlist *)a).num>(*(hashlist *)b).num?1:-1;
}
