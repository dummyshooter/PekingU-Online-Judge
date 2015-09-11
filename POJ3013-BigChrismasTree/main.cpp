#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXIUM 50050

using namespace std;

typedef struct node{
	int num;
	int w;
	struct node* next;
} EdgeNode;

const long long INF=0x7f7f7f7f7f7f7f7f;
EdgeNode *AdjList[MAXIUM];
bool flag[MAXIUM];
int weight[MAXIUM];
long long dist[MAXIUM];
int queue[MAXIUM];
int front,rear;
int vnum,ednum;


int add(int a,int b,int weight);
void SPFA(int s);

int main()
{
    int casenum,i;

    cin>>casenum;
    while(casenum--){
        memset(AdjList,0,sizeof(AdjList));
        int tmpa,tmpb,tmpc;
        cin>>vnum>>ednum;
        for(i=1;i<=vnum;i++)
            scanf("%d",&weight[i]);
        for(i=1;i<=ednum;i++){
            scanf("%d%d%d",&tmpa,&tmpb,&tmpc);
            add(tmpa,tmpb,tmpc);
            add(tmpb,tmpa,tmpc);
        }
        SPFA(1);

        int sign=1;
        long long ans=0;
        for(i=1;i<=vnum;i++){
            if(dist[i]==INF){
                sign=0;
                break;
            }
            ans+=dist[i]*(long long)(weight[i]);
        }

        if(sign)
            printf("%lld\n",ans);
        else
            cout<<"No Answer\n";
    }
    return 0;
}

int add(int a,int b,int weight)
{
	EdgeNode *ptr=AdjList[a];

	if(AdjList[a]==NULL){
		AdjList[a]=(EdgeNode *)malloc(sizeof(EdgeNode));
		AdjList[a]->num=b;
		AdjList[a]->w=weight;
		AdjList[a]->next=NULL;
		return 0;
	}

	while(ptr->next!=NULL){
		if(b==ptr->num){
			if(weight<ptr->w)
				ptr->w=weight;
            return 0;
		}
		ptr=ptr->next;
	}

	if(b==ptr->num){
        if(weight<ptr->w)
            ptr->w=weight;
        return 0;
    }

	ptr->next=(EdgeNode *)malloc(sizeof(EdgeNode));
	ptr->next->num=b;
	ptr->next->w=weight;
	ptr->next->next=NULL;
	return 0;
}

void SPFA(int s)
{
    int tmpa,tmpb,tmpw;

    front=rear=0;
    memset(flag,false,sizeof(flag));
    memset(dist, 0x7f, sizeof(dist));

    dist[s]=0;
    flag[s]=true;
    queue[rear]=s;
    rear=(rear+1)%MAXIUM;

    while(front!=rear){
        tmpa=queue[front];
        front=(front+1)%MAXIUM;
        EdgeNode *ptr;
        for(ptr=AdjList[tmpa];ptr!=NULL;ptr=ptr->next){
            tmpb=ptr->num;
            tmpw=ptr->w;
            if(dist[tmpb]>dist[tmpa]+(long long)tmpw)
                dist[tmpb]=dist[tmpa]+(long long)tmpw;
            if(!flag[tmpb]){
                queue[rear]=tmpb;
                rear=(rear+1)%MAXIUM;
                flag[tmpb]=true;
            }
        }
    }
    return;
}
