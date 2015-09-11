#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int matrix[105][105];
	int sum[105][105];
	int N,i,j,k,max=0;

	memset(sum,0,sizeof(sum));
	cin>>N;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++){
			scanf("%d",&matrix[i][j]);
			sum[i][j]=sum[i][j-1]+matrix[i][j];
		}

	for(i=1;i<=N;i++)
		for(j=0;j<i;j++){
			int tmax=0,tmp=0;
			for(k=1;k<=N;k++){
				tmp+=sum[k][i]-sum[k][j];
				if(tmp>tmax)
					tmax=tmp;
				else if(tmp<0)
					tmp=0;
			}
			if(tmax>max)
				max=tmax;
		}

	cout<<max<<'\n';
	return 0;
}
