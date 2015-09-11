#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int casenum,fund,time,N;
    int i,j,k;
    int value[15],earn[15];
    int dp[50000];

    cin>>casenum;
    while(casenum--){
        scanf("%d%d%d",&fund,&time,&N);
        int ans=fund;
        fund/=1000;
        for(i=1;i<=N;i++){
            scanf("%d%d",&value[i],&earn[i]);
            value[i]/=1000;
        }
        for(i=1;i<=time;i++){
            memset(dp,0,sizeof(dp));
            for(j=1;j<=N;j++)
                for(k=value[j];k<=fund;k++)
                    if(dp[k]<dp[k-value[j]]+earn[j])
                        dp[k]=dp[k-value[j]]+earn[j];
            int tmax=0;
            for(k=0;k<=fund;k++)
                if(tmax<dp[k])
                    tmax=dp[k];
            ans+=tmax;
            fund=ans/1000;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
