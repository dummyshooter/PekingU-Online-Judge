#include <iostream>
#include <cstdio>
#define MAXIUM 1030
using namespace std;

int N;
int treearray[MAXIUM][MAXIUM];

void add(int x,int y,int value);
int sum(int x,int y);
int lowbit(int x);

int main()
{
    int op;
    while(1){
        scanf("%d",&op);
        switch(op){
            case 3:
                return 0;
                break;
            case 0:
                scanf("%d",&N);
                break;
            case 1:
                int x,y,value;
                scanf("%d%d%d",&x,&y,&value);
                add(x+1,y+1,value);
                break;
            case 2:
                int a,b,c,d,tsum=0;
                scanf("%d%d%d%d",&a,&b,&c,&d);
                tsum+=sum(c+1,d+1);
                tsum+=sum(a,b);
                tsum-=sum(a,d+1);
                tsum-=sum(c+1,b);
                printf("%d\n",tsum);
                break;
        }
    }
    return 0;
}

void add(int x,int y,int value)
{
    for(;x<=N;x+=lowbit(x))
        for(int i=y;i<=N;i+=lowbit(i))
            treearray[x][i]+=value;
}

int sum(int x,int y)
{
    int tmpsum=0;

    for(;x>0;x-=lowbit(x))
        for(int i=y;i>0;i-=lowbit(i))
            tmpsum+=treearray[x][i];

    return tmpsum;
}

int lowbit(int x)
{
    return x&(-x);
}
