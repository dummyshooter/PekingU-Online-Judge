#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 999999

using namespace std;

char str[4050][205];
int len[4050];
int next[205];

bool judge(char *buff,int N,int spec);
bool kmp(char *buff,int m,int length);

int main()
{
	int i,j,N,tmpmin=INF,tmpsign;
	char tmp[205];

	while(cin>>N&&N){
		int sign=false;
		getchar();
		for(i=1;i<=N;i++){
			gets(&str[i][1]);
			len[i]=strlen(&str[i][1]);
			if(len[i]<tmpmin){
				tmpmin=len[i];
				tmpsign=i;
			}
		}
		memset(tmp,'z',sizeof(tmp));
		for(i=tmpmin;i>0;i--){
			for(j=1;j<=len[tmpsign]-i+1;j++){
				char buff[205];
				strcpy(&buff[1],&str[tmpsign][j]);
				buff[i+1]='\0';
				if(judge(buff,N,tmpsign)){
					if(strcmp(tmp,&buff[1])>0)
						strcpy(tmp,&buff[1]);
					sign=true;
				}
			}
			if(sign)
				break;
		}
		if(sign)
			printf("%s\n",tmp);
		else
			printf("IDENTITY LOST\n");
	}
	return 0;
}

bool judge(char *buff,int N,int spec)
{
	int i,j=0,length=strlen(&buff[1]);
	next[1]=0;
	for(i=2;i<=length;i++){
		while(j>0&&buff[i]!=buff[j+1])
			j=next[j];
		if(buff[i]==buff[j+1])
			j++;
		next[i]=j;
	}
	for(int p=1;p<=N;p++){
		if(p==spec)
			continue;
		if(!kmp(buff,p,length))
			return false;
	}
	return true;
}

bool kmp(char *buff,int m,int length)
{
	int i,j=0;
	for(i=1;i<=len[m];i++){
		while(j>0&&str[m][i]!=buff[j+1])
			j=next[j];
		if(str[m][i]==buff[j+1])
			j++;
		if(j==length)
			return true;
	}
	return false;
}




