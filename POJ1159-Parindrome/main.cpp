#include <iostream>
#define MAXIUM 5050
using namespace std;

int main()
{
    int N,i,j;
    char buff[MAXIUM];
    short dp[2][MAXIUM];

	memset(dp,0,sizeof(dp));

    scanf("%d",&N);
    getchar();
    gets(buff);

    int length=strlen(buff);

    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            if(buff[i]==buff[length-1-j])
                dp[1][j+1]=dp[0][j]+1;
            else if(dp[1][j]>dp[0][j+1])
                dp[1][j+1]=dp[1][j];
			else
				dp[1][j+1]=dp[0][j+1];
		}
		for(j=0;j<=length;j++){
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
	}

    cout<<(length-dp[0][length])<<"\n";

    return 0;
}

