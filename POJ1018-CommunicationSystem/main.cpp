#include <iostream>
#include <cstdio>
#include <cstring>

#define NIL 9999999

using namespace std;
int main()
{
    int casenum,i,j;

    cin>>casenum;
    while(casenum-->0){
        int dnum,mnum[105]={0};
        int bandwidth[105][105],price[105][105];
        int dpbw[105]={0};
        int dpp[105]={0};
        double rate[105]={0.0};

        memset(bandwidth,0,sizeof(bandwidth));
        memset(price,0,sizeof(price));

        cin>>dnum;
        for(i=1;i<=dnum;i++){
            cin>>mnum[i];
            for(j=1;j<=mnum[i];j++)
                cin>>bandwidth[i][j]>>price[i][j];
        }

        dpbw[0]=NIL;

        for(i=1;i<=dnum;i++)
            for(j=1;j<=mnum[i];j++)
                if(min(dpbw[i-1],bandwidth[i][j])/(dpp[i-1]+price[i][j])>rate[i]){
                    rate[i]=min(dpbw[i-1],bandwidth[i][j])/(dpp[i-1]+price[i][j]);
                    dpp[i]=dpp[i-1]+price[i][j];
                    dpbw[i]=min(dpbw[i-1],bandwidth[i][j]);
                }

        printf("%.3f\n",rate[dnum]);
        }

    return 0;
}




