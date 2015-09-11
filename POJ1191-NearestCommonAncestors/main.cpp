#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAXIUM 105

typedef struct node{
	int info;
	struct node* next;
} EdgeNode;

EdgeNode *AdjList[MAXIUM];
int used[MAXIUM];
int anc[MAXIUM];
int hash[MAXIUM];
int depth[MAXIUM];
int N;

void dfs(int v);
int add(int a,int b);

using namespace std;
int main()
{
    int casenum;
    int a,b,i;

    cin>>casenum;
    while(casenum-->0){
        memset(AdjList,0,sizeof(AdjList));
		memset(used,0,sizeof(used));
		memset(hash,0,sizeof(hash));
		memset(anc,0,sizeof(anc));
		memset(depth,0,sizeof(depth));
        cin>>N;
		for(i=1;i<N;i++){
			scanf("%d%d",&a,&b);
			add(a,b);
			hash[b]=1;
		}
		for(i=1;i<=N;i++)
			if(!hash[i])
				break;
		dfs(i);
		cin>>a>>b;
		if(depth[a]>depth[b])
			for(i=depth[a]-depth[b];i>0;i--)
				a=anc[a];
		else
			for(i=depth[b]-depth[a];i>0;i--)
				b=anc[b];
		while(a!=b){
		    a=anc[a];
		    b=anc[b];
		}
		cout<<a<<'\n';
    }
    return 0;
}

void dfs(int v)
{
    EdgeNode *ptr=AdjList[v];

	used[v]=1;
    while(ptr!=NULL){
        if(!used[ptr->info]){
			anc[ptr->info]=v;
			depth[ptr->info]=depth[v]+1;
            dfs(ptr->info);
        }
		ptr=ptr->next;
	}
    used[v]=2;
    return;
}

int add(int a,int b)
{
	EdgeNode *ptr=AdjList[a];

	if(AdjList[a]==NULL){
		AdjList[a]=(EdgeNode *)malloc(sizeof(EdgeNode));
		AdjList[a]->info=b;
		AdjList[a]->next=NULL;
		return 0;
	}

	while(ptr->next!=NULL)
		ptr=ptr->next;

	ptr->next=(EdgeNode *)malloc(sizeof(EdgeNode));
	ptr->next->info=b;
	ptr->next->next=NULL;
	return 0;
}
