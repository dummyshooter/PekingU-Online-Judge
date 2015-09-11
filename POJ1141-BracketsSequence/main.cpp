#include <iostream>
#define MAXIUM 105
#define NIL 99999

int print(char *,int,int);

int path[MAXIUM][MAXIUM];

using namespace std;
int main()
{
	int i,j;
	char buff[MAXIUM];
	int dp[MAXIUM][MAXIUM];


	memset(dp,0,sizeof(dp));

	gets(buff);
	int length=strlen(buff);

	for(i=0;i<length;i++)
		dp[i][i]=1;

	for(i=1;i<length;i++)
		for(j=0;j<length-i;j++){
			int k=i+j;
			dp[j][k]=NIL;
			if((buff[j]=='['&&buff[k]==']')||(buff[j]=='('&&buff[k]==')')){
				dp[j][k]=dp[j+1][k-1];
				path[j][k]=-1;
			}
			for(int m=j;m<k;m++)
				if(dp[j][k]>(dp[j][m]+dp[m+1][k])){
					dp[j][k]=dp[j][m]+dp[m+1][k];
					path[j][k]=m;
				}
		}

	print(buff,0,length-1);
	cout<<'\n';

	return 0;
}

int print(char *buff,int left,int right)
{
	if(left>right)
		return 0;
	else if(left==right){
		if(buff[left]=='('||buff[left]==')')
			cout<<"()";
		else if(buff[left]=='['||buff[left]==']')
			cout<<"[]";
	}
	else if(path[left][right]==-1){
		cout<<buff[left];
		print(buff,left+1,right-1);
		cout<<buff[right];
	}
	else{
		print(buff,left,path[left][right]);
		print(buff,path[left][right]+1,right);
	}
	return 0;
}








