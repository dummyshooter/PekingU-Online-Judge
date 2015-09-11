#include <iostream>
#define MAXIUM 450000
using namespace std;

typedef struct TreeNode
{
	int left;
	int right;
	int color;
} node;

int L,T,O;

node segtree[MAXIUM];
int hash[35];
int output;

void init(int sub,int left,int right);
void ch(int sub,int left,int right,int color);
void se(int sub,int left,int right);

int main()
{
    int color[100050]={1};

    scanf("%d%d%d",&L,&T,&O);
	getchar();
	init(1,1,L);
    while(O-->0){
        char op;
        scanf("%c",&op);
        if(op=='C'){
            int left,right,ins;
            scanf("%d%d%d",&left,&right,&ins);
			getchar();
			ch(1,left,right,ins);
        }
        else{
			output=0;
            memset(hash,0,sizeof(hash));
            int left,right;
			scanf("%d%d",&left,&right);
			getchar();
			se(1,left,right);
            printf("%d\n",output);
        }
    }
    return 0;
}


void init(int sub,int left,int right)
{
	int mid=(left+right)/2;

	segtree[sub].left=left;
	segtree[sub].right=right;
	segtree[sub].color=1;
	if(left<right){
		init(2*sub,left,mid);
		init(2*sub+1,mid+1,right);
	}
}

void ch(int sub,int left,int right,int color)
{
	int mid=(segtree[sub].left+segtree[sub].right)/2;

	if(segtree[sub].left==left&&segtree[sub].right==right){
		segtree[sub].color=color;
		return;
	}
	else{
		if(segtree[sub].color){
			ch(2*sub,segtree[sub].left,mid,segtree[sub].color);
			ch(2*sub+1,mid+1,segtree[sub].right,segtree[sub].color);
		}
		segtree[sub].color=0;
		if(mid+1<=left)
			ch(2*sub+1,left,right,color);
		else if(mid>=right)
			ch(2*sub,left,right,color);
		else{
			ch(2*sub,left,mid,color);
			ch(2*sub+1,mid+1,right,color);
		}
	}
}

void se(int sub,int left,int right)
{
	int mid=(segtree[sub].left+segtree[sub].right)/2;

	if(segtree[sub].color){
		if(!hash[segtree[sub].color]){
			hash[segtree[sub].color]=1;
			output++;
		}
		return;
	}

	if(mid+1<=left)
		 se(sub*2+1,left,right);
    else if(mid>=right)
		 se(sub*2,left,right);
	else{
		 se(sub*2,left,mid);
		 se(sub*2+1,mid+1,right);
	 }
	return;
}

















