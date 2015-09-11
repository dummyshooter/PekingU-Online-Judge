#include <iostream>
using namespace std;

int main()
{
	int i,num[10];

	while(1){
		int count=0;
		bool flag=false;

		for(i=1;i<=6;i++){
			cin>>num[i];
			if(num[i])
				flag=true;
		}
		if(!flag)
			break;

		count+=num[6],num[6]=0;

		count+=num[5];
		num[1]=max(0,num[1]-11*num[5]),num[5]=0;

		count+=num[4];
		if((num[2]-5*num[4])<0)
			num[1]=max(0,num[1]-20*num[4]+4*num[2]),num[2]=0;
		else
			num[2]=num[2]-5*num[4];

		count+=num[3]/4,num[3]%=4;
		if(num[3]){
			count++;
			if(num[3]==3){
				num[3]=0;
				int tmp=9-min(1,num[2])*4;
				num[2]=max(0,num[2]-1);
				num[1]=max(0,num[1]-tmp);
			}
			else if(num[3]==2){
				num[3]=0;
				int tmp=18-min(3,num[2])*4;
				num[2]=max(0,num[2]-3);
				num[1]=max(0,num[1]-tmp);
			}
			else if(num[3]==1){
				num[3]=0;
				int tmp=27-min(5,num[2])*4;
				num[2]=max(0,num[2]-5);
				num[1]=max(0,num[1]-tmp);
			}
		}

		count+=num[2]/9,num[2]%=9;
		if(num[2]){
			count++;
			num[1]=max(0,num[1]-36+4*num[2]),num[2]=0;
		}

		count+=num[1]/36,num[1]%=36;
		if(num[1])
			count++;
		cout<<count<<'\n';
	}
	return 0;
}
