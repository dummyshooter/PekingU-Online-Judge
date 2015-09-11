#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool map[505][505];
bool state[505];
int result[505];
int P,N;

bool Hungary(int a);

int main()
{
    int casenum;
    int i,j,tmp1,tmp2;

    cin>>casenum;
    while(casenum--){
        memset(result,0,sizeof(result));
        memset(map,false,sizeof(map));
        scanf("%d%d",&P,&N);
        for(i=1;i<=P;i++){
            scanf("%d",&tmp1);
            for(j=1;j<=tmp1;j++){
                scanf("%d",&tmp2);
                map[tmp2][i]=true;
            }
        }
        int ans=0;
        for(i=1;i<=P;i++){
            memset(state,false,sizeof(state));
            if(Hungary(i))
                ans++;
        }
        if(ans==P)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

bool Hungary(int a)
{
    for(int i=1;i<=N;i++){
        if(map[i][a]&&!state[i]){
            state[i]=true;
            if(result[i]==0||Hungary(result[i])){
                result[i]=a;
                return true;
            }
        }
    }
    return false;
}
