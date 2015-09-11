#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int casenum,n,a;

	cin>>casenum;
	while(casenum--){
		int ans=0,tmp=-1;
		bool flag=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			if((flag&&tmp<a)||((!flag)&&tmp>a)){
					ans++; flag=!flag;
			}
			tmp=a;
		}
		printf("%d\n",ans);
	}
	return 1;
}
