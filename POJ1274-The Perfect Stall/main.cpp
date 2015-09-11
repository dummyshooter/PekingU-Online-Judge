#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,M;
bool map[205][205];
bool state[205];
int result[205];

bool Hungary(int i);

int main()
{
    int i,j,tmp1,tmp2;

    while(cin>>N>>M&&(N||M)){
        memset(map,false,sizeof(map));
        memset(result,0,sizeof(result));
        for(i=1;i<=N;i++){
            scanf("%d",&tmp1);
            for(j=1;j<=tmp1;j++){
                scanf("%d",&tmp2);
                map[i][tmp2]=true;
            }
        }
        int ans=0;
        for(i=1;i<=N;i++){
            memset(state,false,sizeof(state));
            if(Hungary(i))
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

bool Hungary(int i)
{
    int j;

    for(j=1;j<=M;j++)
        if(map[i][j]&&!state[j]){
            state[j]=true;
            if(result[j]==0||Hungary(result[j])){
                result[j]=i;
                return true;
            }
        }
    return false;
}
