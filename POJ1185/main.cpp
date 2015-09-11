#include <iostream>
#include <cstdio>

int dp[105][65][65];

using namespace std;
int main()
{
    char tmp;
    int N,M,i,j,k,p;
    unsigned int terrain[105]={0};
    unsigned int status[65]={0};
    unsigned int sign=1;
    int statnum[65]={0};

    scanf("%d%d",&N,&M);
	getchar();

    for(i=1;i<M;i++)
        sign*=2;

    for(i=1;i<=N;i++){
        k=0;
        while(k<M){
			cin>>tmp;
            if(tmp=='H')
                terrain[i]|=sign>>k;
			k++;
		}
    }


    unsigned int count=0;
    unsigned int mask;
    unsigned int mask_=1<<M;
    for(mask=0;mask<mask_;mask++){
        unsigned int tmp=mask;
        if(((tmp<<1)&mask)||((tmp<<2))&mask)
            continue;
        for(tmp=sign;tmp>0;tmp>>=1)
            if(tmp&mask)
                statnum[count]++;
        status[count++]=mask;
    }


    for(i=1;i<=N;i++)
        for(j=0;j<count;j++){
			if(terrain[i]&status[j])
                continue;
			if(i==1)
				dp[1][j][0]=statnum[j];
			else if(i==2){
				for(k=0;k<count;k++)
					if((terrain[1]&status[k])||(status[j]&status[k]))
						continue;
					else if(dp[1][k][0]+statnum[j]>dp[2][j][k])
						dp[2][j][k]=dp[1][k][0]+statnum[j];
			}
			else{

            for(k=0;k<count;k++){
                if((terrain[i-1]&status[k])||(status[k]&status[j]))
                    continue;
                for(p=0;p<count;p++){
					if(i==2&&p>0){
						j=count;
						k=count;
						break;
					}
					else if(terrain[i-2]&status[p])
						continue;
                    else if((status[p]&status[k])||(status[p]&status[j]))
                        continue;
                    else if(dp[i-1][k][p]+statnum[j]>dp[i][j][k])
                        dp[i][j][k]=dp[i-1][k][p]+statnum[j];
                }
			}
            }
        }

    int tmpmax=0;

    for(k=0;k<count;k++)
        for(j=0;j<count;j++)
            if(dp[N][j][k]>tmpmax)
                tmpmax=dp[N][j][k];

    printf("%d\n",tmpmax);

    return 0;
}

