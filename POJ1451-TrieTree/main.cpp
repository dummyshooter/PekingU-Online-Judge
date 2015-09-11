#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#define MAXIUM 100000
#define INF 9999999
using namespace std;

typedef struct TRIE
{
	int f,next[26];
} Trie;
typedef struct NODE
{
	string str;
	int pos,f,depth;
} Node;
struct cmp{
	bool operator()(const Node &a,const Node &b){
		if(a.depth>b.depth)
			return true;
		else if(a.depth==b.depth&&a.f<b.f)
			return true;
		else
			return false;
	}
};
Trie t[MAXIUM];
priority_queue <Node,vector<Node>,cmp> q;
int lc;

void init();
void loc(char a,int *left,int *right);
void add(char *buff,int freq);
void find(char *buff);

int main()
{
	int casenum,i,freq,N,M;
	char buff[101];

	scanf("%d",&casenum);
	for(int k=1;k<=casenum;k++){
		lc=0;
		scanf("%d",&N);
		for(i=0;i<26;i++)
			t[0].next[i]=-1;
		for(i=0;i<N;i++){
			scanf("%s%d",buff,&freq);
			add(buff,freq);
		}
		printf("Scenario #%d:\n",k);
		scanf("%d",&M);
		for(i=0;i<M;i++){
			scanf("%s",buff);
			find(buff);
			printf("\n");
		}
		printf("\n");
	}
	return 1;
}

void add(char *buff,int freq)
{
	int len=strlen(buff),i,j;
	int ptr=0;
	for(i=0;i<len;i++){
		if(t[ptr].next[buff[i]-'a']!=-1)
			ptr=t[ptr].next[buff[i]-'a'];
		else{
			ptr=t[ptr].next[buff[i]-'a']=++lc;
			for(j=0;j<26;j++)
				t[ptr].next[j]=-1;
			t[ptr].f=0;
		}
		t[ptr].f+=freq;
	}
}

void find(char *buff)
{
	Node tmp,tmp_;
	int left,right,i,j;
	int len=strlen(buff);
	if(len==1)
		return;
	tmp.pos=0; tmp.depth=0; tmp.f=INF; tmp.str="";
	q.push(tmp);
	for(i=0;i<len-1;i++){
		loc(buff[i],&left,&right);
		int sta=tmp.depth;
		while(tmp.depth==sta&&!q.empty()){
			q.pop();
			for(j=left;j<=right;j++){
				if(t[tmp.pos].next[j]==-1)
					continue;
				tmp_.depth=tmp.depth+1; tmp_.pos=t[tmp.pos].next[j]; tmp_.f=t[tmp_.pos].f;
				char temp=j+'a';
				tmp_.str=tmp.str+temp;
				q.push(tmp_);
			}
			tmp=q.top();
		}
		if(q.empty())
			printf("MANUALLY\n");
		else
			cout<<tmp.str<<'\n';
	}
	while(!q.empty())
		q.pop();
	return;
}

void loc(char a,int *left,int *right)
{
	switch(a){
		case '2': *left=0; *right=2; return;
		case '3': *left=3; *right=5; return;
		case '4': *left=6; *right=8; return;
		case '5': *left=9; *right=11; return;
		case '6': *left=12; *right=14; return;
		case '7': *left=15; *right=18; return;
		case '8': *left=19; *right=21; return;
		case '9': *left=22; *right=25; return;
	}
}
