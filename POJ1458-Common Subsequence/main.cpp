#include <iostream>
#include <string.h>
#define MAXIUM 500
using namespace std;
int main()
{
    char a[MAXIUM],b[MAXIUM];
    int dp[MAXIUM][MAXIUM];
    int i,j;

    while(cin>>a>>b){
        int alen=strlen(a);
        int blen=strlen(b);
        memset(dp,0,sizeof(dp));

        for(i=1;i<=alen;i++)
            for(j=1;j<=blen;j++)
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else if(dp[i-1][j]>=dp[i][j-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-1];

        cout<<dp[alen][blen]<<"\n";
    }

    return 0;
}
