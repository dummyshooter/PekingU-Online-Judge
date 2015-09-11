#include <iostream>
#include <cstring>
#define MAXIUM 37

unsigned long bitdata[MAXIUM];
void dfs(int i,int k,unsigned long bitd);
int bits(unsigned long bitd);
int maxp;

using namespace std;
int main()
{
    int casenum,N;

    cin>>casenum;
    while(casenum-->0){
        memset(bitdata,0,sizeof(bitdata));
        maxp=0;
        cin>>N;
        int a,b;
        for(int i=1;i<=N;i++){
            cin>>a>>b;
            bitdata[a]|=1L<<(b-1);
        }
        dfs(0,0,~0);
        cout<<maxp<<'\n';
    }
    return 0;
}

void dfs(int i,int k,unsigned long bitd)
{
    int num=bits(bitd);

    if(num<k)
        return;
    else{
        maxp=max(maxp,k);
        for(int j=i+1;j<=36;j++)
            dfs(j,k+1,bitd&bitdata[j]);
    }
}

int bits(unsigned long bitd)
{
    int count=0;

    while(bitd){
        if(bitd&1)
            count++;
        bitd>>=1;
    }
    return count;
}
