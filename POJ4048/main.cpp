#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LIMIT 1e-12
#define MLIMIT -1e-12
using namespace std;

int dot[1505][4],N,tmax;

void check(int x,int y);

int main()
{
    int casenum,i;
    cin>>casenum;
    while(casenum--){
        tmax=0;
        cin>>N;
        for(i=1;i<=N;i++)
            scanf("%d%d%d%d",&dot[i][0],&dot[i][1],&dot[i][2],&dot[i][3]);
        scanf("%d%d",&dot[0][0],&dot[0][1]);
        for(i=1;i<=N;i++){
            check(dot[i][0],dot[i][1]);
            check(dot[i][2],dot[i][3]);
        }
        printf("%d\n",tmax);
    }
    return 0;
}

void check(int x,int y)
{
    double tx,ty;
    int cnt=0;
    for(int i=1;i<=N;i++){
        int up=(dot[0][0]*y-x*dot[0][1])*(dot[i][2]-dot[i][0]);
        up-=(x-dot[0][0])*(dot[i][0]*dot[i][3]-dot[i][1]*dot[i][2]);
        tx=(double)up;
        int di=(dot[i][2]-dot[i][0])*(y-dot[0][1])-(x-dot[0][0])*(dot[i][3]-dot[i][1]);
        if(di==0)
            continue;
        tx/=(double)di;
        if(dot[i][2]==dot[i][0])
            ty=(double)y+(double)((y-dot[0][1])*(tx-dot[0][0]))/(double)(x-dot[0][0]);
        else
            ty=(double)dot[i][1]+(double)((dot[i][3]-dot[i][1])*(tx-dot[i][0]))/(double)(dot[i][2]-dot[i][0]);
	if((tx-(double)(dot[0][0]))*(double(x)-(double)(dot[0][0]))<MLIMIT||(ty-(double)(dot[0][1]))*(double(y)-(double)(dot[0][1]))<MLIMIT)
		continue;
        if((fabs(tx-(double)(dot[i][0]))<=LIMIT&&fabs(ty-(double)(dot[i][1]))<=LIMIT)||(fabs(tx-(double)(dot[i][2]))<=LIMIT&&fabs(ty-(double)(dot[i][3]))<=LIMIT))
            cnt++;
        else if((tx-(double)(dot[i][0]))*(tx-(double)(dot[i][2]))<=0)
           cnt++;
    }
    if(cnt>tmax)
        tmax=cnt;
    return;
}
