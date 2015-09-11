#include <iostream>
#include <cstring>
#include <math.h>
#define MAXIUM 50

int s(int a,int b,int c);

using namespace std;
int main()
{
    int N,i,j,k,sum=0;
    int line[MAXIUM]={0};
    int dp[MAXIUM][MAXIUM];

    memset(dp,0,sizeof(dp));
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>line[i];
        sum+=line[i];
    }

    dp[0][0]=1;

    for(i=1;i<=N;i++)
        for(j=sum/2;j>=0;j--)
            for(k=j;k>=0;k--){
                if(2*(j+k)<=sum)
                    continue;
                if(line[i]<=j)
                    dp[j][k]|=dp[j-line[i]][k];
                if(line[i]<=k)
                    dp[j][k]|=dp[j][k-line[i]];
            }
    int max=0;

    for(j=sum/2;j>0;j--)
        for(k=j;k>0;k--)
            if(dp[j][k]){
                int tmp=s(j,k,sum-j-k);
                if(tmp==0){
                    cout<<"-1\n";
                    return 0;
                }
                if(tmp>max)
                    max=tmp;
            }

    cout<<max<<'\n';
    return 0;
}

int s(int a,int b,int c)
{
    double p=(a+b+c)/2;
    int res=sqrt(p*(p-a)*(p-b)*(p-c));

    return res;
}
