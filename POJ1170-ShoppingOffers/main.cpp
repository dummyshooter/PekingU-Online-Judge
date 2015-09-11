#include <iostream>
#include <cstring>
#define MAXIUM 6
#define NIL 9999999

typedef struct offer
{
    int nump[MAXIUM];
    int price;
} offerp;

using namespace std;
int main()
{
    int casenum;
    int offernum;
    int hash[1000]={0};
    int num[MAXIUM]={0};
    int value[MAXIUM]={0};
    offerp offer[100];
    int dp[MAXIUM][MAXIUM][MAXIUM][MAXIUM][MAXIUM];
    int i,j,lp1,lp2,lp3,lp4,lp5;

    memset(offer,0,sizeof(offer));
    memset(dp,NIL,sizeof(dp));

    cin>>casenum;
    for(i=1;i<=casenum;i++){
		int tmp;
        cin>>tmp>>num[i]>>value[i];
        hash[tmp]=i;
    }

    cin>>offernum;
    for(i=1;i<=offernum;i++){
        int tmp;
        cin>>tmp;
        for(j=1;j<=tmp;j++){
            int tmp_;
            cin>>tmp_;
            cin>>offer[i].nump[hash[tmp_]];
        }
        cin>>offer[i].price;
    }


    for(lp1=0;lp1<=num[1];lp1++)
         for(lp2=0;lp2<=num[2];lp2++)
             for(lp3=0;lp3<=num[3];lp3++)
                 for(lp4=0;lp4<=num[4];lp4++)
                     for(lp5=0;lp5<=num[5];lp5++){
						dp[lp1][lp2][lp3][lp4][lp5]=lp1*value[1]+lp2*value[2]+lp3*value[3]+lp4*value[4]+lp5*value[5];
                        for(i=1;i<=offernum;i++){
							if((lp1-offer[i].nump[1])>=0&&(lp2-offer[i].nump[2])>=0&&(lp3-offer[i].nump[3])>=0&&(lp4-offer[i].nump[4])>=0&&(lp5-offer[i].nump[5]>=0))
								if(dp[lp1][lp2][lp3][lp4][lp5]>dp[lp1-offer[i].nump[1]][lp2-offer[i].nump[2]][lp3-offer[i].nump[3]][lp4-offer[i].nump[4]][lp5-offer[i].nump[5]]+offer[i].price)
									dp[lp1][lp2][lp3][lp4][lp5]=dp[lp1-offer[i].nump[1]][lp2-offer[i].nump[2]][lp3-offer[i].nump[3]][lp4-offer[i].nump[4]][lp5-offer[i].nump[5]]+offer[i].price;
								}
					 }

    cout<<dp[num[1]][num[2]][num[3]][num[4]][num[5]]<<"\n";
    return 0;
}
