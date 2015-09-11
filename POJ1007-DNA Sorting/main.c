#include <stdio.h>
#include <string.h>

int dp(char *,int);

int main()
{
	int n,m,i,j;
	int tmp;
	char str[105][55];
	char tmp_[55];
	int inversion[105];

	scanf("%d%d",&n,&m);
	getchar();

	for(i=1;i<=m;i++)
		gets(str[i]);

	for(i=1;i<=m;i++)
		inversion[i]=dp(str[i],n);

	for(i=2;i<=m;i++){
		tmp=inversion[i];
		strcpy(tmp_,str[i]);
		for(j=i;j>1&&inversion[j-1]>tmp;j--){
			strcpy(str[j],str[j-1]);
			inversion[j]=inversion[j-1];
		}
		strcpy(str[j],tmp_);
		inversion[j]=tmp;
	}

	for(i=1;i<=m;i++)
		printf("%s\n",str[i]);

	return 0;
}
		

int dp(char *head,int n)
{
	int inv[55];
	int tmp;
	int i,j;

	inv[0]=0;
	
	for(i=1;i<n;i++){
		tmp=0;
		for(j=0;j<i;j++)
			if(head[i]<head[j])
				tmp++;
		inv[i]=inv[i-1]+tmp;
	}

	return inv[n-1];
}



	