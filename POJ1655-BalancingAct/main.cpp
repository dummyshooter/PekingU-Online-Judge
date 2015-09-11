#include <iostream>
#define MAXIUM 20050
#define NIL 999999

typedef struct node{
	int info;
	struct node* next;
} EdgeNode;

EdgeNode *AdjList[MAXIUM];
int N;
int count[MAXIUM];
int used[MAXIUM];
int as[MAXIUM];
int un[MAXIUM];

int add(int a,int b);
int dfs(int v);

using namespace std;

int main()
{
	int casenum;
	int a,b;
	int i;

	cin>>casenum;
	while(casenum-->0){
		memset(AdjList,0,sizeof(AdjList));
		memset(count,0,sizeof(count));
		memset(used,0,sizeof(used));
		memset(as,0,sizeof(as));
		memset(un,0,sizeof(un));
		cin>>N;
		for(i=1;i<N;i++){
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		count[1]=dfs(1);

		for(i=1;i<=N;i++){
			int tmp=count[i];
			int tmp_=count[as[i]];
			EdgeNode *ptr=AdjList[i];
			count[as[i]]=N-count[i]-2;
			count[i]=N-1;
			while(ptr){
				if((count[ptr->info]+1)>un[i])
					un[i]=count[ptr->info]+1;
				ptr=ptr->next;
			}
			count[i]=tmp;
			count[as[i]]=tmp_;
		}

		int tmpmin=NIL;
		int extmp=0;

		for(i=1;i<=N;i++)
			if(un[i]<tmpmin){
				tmpmin=un[i];
				extmp=i;
			}

		cout<<extmp<<' '<<tmpmin<<"\n";
	}
	return 0;
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

int dfs(int v)
{
	EdgeNode *ptr=AdjList[v];

	used[v]=1;
    while(ptr!=NULL){
        if(!used[ptr->info]){
			as[ptr->info]=v;
            count[v]+=dfs(ptr->info)+1;
        }
		ptr=ptr->next;
	}
    used[v]=2;
    return count[v];
}
