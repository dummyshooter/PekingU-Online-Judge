#include <iostream>
#include <cstring>
#define NIL 99999999
using namespace std;

int N;
int matrix[505][505];
int key[505];
long long sum;
bool hash[505];

void Prim();

int main()
{
    int i,j;

    while(cin>>N&&N){
        sum=0;
        memset(hash,false,sizeof(hash));
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                cin>>matrix[i][j];
        Prim();
        cout<<sum<<'\n';
    }
    return 0;
}

void Prim()
{
    int i;
    int count=0;

    for(i=2;i<=N;i++)
        key[i]=NIL;
    key[1]=0;

    while(count<N){
        int tmpmin=NIL;
        int tmp;
        for(i=1;i<=N;i++)
            if((!hash[i])&&key[i]<tmpmin){
                tmpmin=key[i];
                tmp=i;
            }
        sum+=tmpmin;
        hash[tmp]=true;
        count++;
        for(i=1;i<=N;i++)
            if((!hash[i])&&matrix[tmp][i]<key[i])
                key[i]=matrix[tmp][i];
    }
    return;
}



