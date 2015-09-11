#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SPE 987654

using namespace std;
int main()
{
    int casenum,m,T,i,j;
    char buff[10];
    int status[55];
    double dp[55][45];

    cin>>casenum;
    while(casenum-->0){
        double sum=0.0;
        memset(dp,0,sizeof(double)*55*45);
		memset(status,0,sizeof(int)*55);
        cin>>m>>T;
        for(i=1;i<=m;i++){
            cin>>buff;
            if(buff[0]=='L')
                status[i]=SPE;
            else if(buff[0]=='-')
                status[i]=-atoi(&buff[1]);
            else
                status[i]=atoi(buff);
        }

        dp[0][0]=1.0;

        for(i=0;i<T;i++)
            for(j=0;j<=m;j++){
                if(status[j+1]==SPE)
                    dp[i+2][j+1]+=dp[i][j]*0.5;
                else
                    dp[i+1][j+1+status[j+1]]+=dp[i][j]*0.5;
                if(status[j+2]==SPE)
                    dp[i+2][j+2]+=dp[i][j]*0.5;
                else
                    dp[i+1][j+2+status[j+2]]+=dp[i][j]*0.5;
            }

        for(i=0;i<=T;i++)
            sum+=dp[i][m+1]+dp[i][m+2];

        if(sum==0.5)
            cout<<"Push. 0.5000\n";
        else if(sum>0.5)
            printf("Bet for. %.4f\n",sum);
        else
            printf("Bet against. %.4f\n",sum);
    }

	return 0;

}
