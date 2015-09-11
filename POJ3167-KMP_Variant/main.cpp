#include <iostream>
#include <cstdio>
using namespace std;

int N,K,S,count;
int a[100050],b[25050],pa[100050][26],pb[25050][26];
int next[25050],ans[100050];

void init();
void pre();
void kmp();
void cal(bool flag,int *equal,int *small,int left,int right);

int main()
{
	int i;
	cin>>N>>K>>S;
	for(i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=K;i++)
		scanf("%d",&b[i]);
	init();
	kmp();
	cout<<count<<'\n';
	for(i=0;i<count;i++)
		printf("%d\n",ans[i]);
}

void init()
{
	int i,j;
	pa[1][a[1]]=1;
	pb[1][b[1]]=1;
	for(i=2;i<=N;i++){
		for(j=1;j<=S;j++)
			pa[i][j]+=pa[i-1][j];
		pa[i][a[i]]++;
	}
	for(i=2;i<=K;i++){
		for(j=1;j<=S;j++)
			pb[i][j]+=pb[i-1][j];
		pb[i][b[i]]++;
	}
	pre();
	return;
}

void pre()
{
	int i,j=0,ae,as,be,bs;
	next[1]=0;
	for(i=2;i<=K;i++){
		cal(false,&ae,&as,1,j+1);
		cal(false,&be,&bs,i-j,i);
		while(j>0&&(ae!=be||as!=bs)){
			j=next[j];
			cal(false,&ae,&as,1,j+1);
			cal(false,&be,&bs,i-j,i);
		}
		if(ae==be&&as==bs)
			j++;
		next[i]=j;
	}
	return;
}

void cal(bool flag,int *equal,int *small,int left,int right)
{
	int i;
	*equal=*small=0;
	if(flag){
		for(i=1;i<a[right];i++)
			*small+=pa[right-1][i]-pa[left-1][i];
		*equal=pa[right-1][a[right]]-pa[left-1][a[right]];
	}
	else{
		for(i=1;i<b[right];i++)
			*small+=pb[right-1][i]-pb[left-1][i];
		*equal=pb[right-1][b[right]]-pb[left-1][b[right]];
	}
	return;
}

void kmp()
{
	int i,j=0,ae,as,be,bs;
	count=0;
	for(i=1;i<=N;i++){
		cal(false,&ae,&as,1,j+1);
		cal(true,&be,&bs,i-j,i);
		while(j>0&&(ae!=be||as!=bs)){
			j=next[j];
			cal(false,&ae,&as,1,j+1);
			cal(true,&be,&bs,i-j,i);
		}
		if(ae==be&&as==bs)
			j++;
		if(j==K){
			ans[count++]=i-j+1;
			j=next[j];
		}
	}
}
