#include<iostream>
using namespace std;
int main(){
	long long list[1510] = {0,1};
	int p2=1,p3=1,p5=1;
	for(int i=2;i<=1500;i++){
		list[i]=min(list[p2]*2,min(list[p3]*3,list[p5]*5));
		if(list[i]==2*list[p2])
            p2++;
		if(list[i]==3*list[p3])
            p3++;
		if(list[i]==5*list[p5])
            p5++;
		}
	int n;
	while(cin>>n&&n)
		cout<<ans[n]<<'\n';
	return 0;
}
