#include <stdio.h>
#include <stdlib.h>

int MaxSequence(int a[],int n)          //动态规划求解最大子序列
{
	int *tmp;
	int max;
	int i;

	tmp=(int *)malloc(sizeof(int)*(n+1));
	max=tmp[1]=a[1];

	if(n==1)
		return max;

	for(i=2;i<=n;i++){
		if(tmp[i-1]>0)
			tmp[i]=tmp[i-1]+a[i];
		else
			tmp[i]=a[i];
		if(tmp[i]>max)
			max=tmp[i];
	}

	free(tmp);
	return max;
}

int main()
{
	int N;
	int i,j,k,buff;
	int max=-200000;
	int matrix[105][105];
	int tmp[105][105];
	int tmp2[105];

	scanf("%d",&N);

	for(i=1;i<=N;i++)
		matrix[0][i]=0;

	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			scanf("%d",&matrix[i][j]);

	for(j=1;j<=N;j++)
		tmp[0][j]=0;

	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			tmp[i][j]=tmp[i-1][j]+matrix[i][j];



	for(i=1;i<=N;i++)
		for(j=0;j<i;j++){
			for(k=1;k<=N;k++)
				tmp2[k]=tmp[i][k]-tmp[j][k];
			buff=MaxSequence(tmp2,N);
			if(buff>max)
				max=buff;
		}

	printf("%d\n",max);
	return 0;
}








