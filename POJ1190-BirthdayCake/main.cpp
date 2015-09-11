#include <iostream>
#include <math.h>
#define vsum(f) (f*f*(f+1)*(f+1)/4)   //前f-1个圆柱的最小体积
#define NIL 9999999
#define MAXHIGH 1000

int smin=NIL;
int N,M;

void dfs(int layers,int radius,int high,int vleft,int s);

using namespace std;
int main()
{
    cin>>N>>M;
    int maxradius=(int)sqrt(double((N-vsum(M))/M))+1;
    dfs(M,maxradius,MAXHIGH,N,0);
    if(smin==NIL)
        cout<<"0\n";
    else
        cout<<smin<<"\n";

    return 0;
}

void dfs(int layers,int radius,int high,int vleft,int s)
{
    if(s+2*vleft/radius>=smin)  //面积判定剪枝
        return;
    if(vleft<vsum(layers))   //体积判定剪枝
        return;
    if(!layers){    //初始化
        if(!vleft&&s<smin)
            smin=s;
        return;
    }
    for(int i=radius-1;i>=layers;i--){
        if(layers==M)
            s=i*i;
        int tmph=(vleft-vsum(layers-1))/(i*i);
        if(tmph>high-1)
            tmph=high-1;
        for(int j=tmph;j>=layers;j--)
            dfs(layers-1,i,j,vleft-i*i*j,s+2*i*j);
    }
}


