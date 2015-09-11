#include <iostream>
using namespace std;
int main()
{
	char head,tmp;

    while((head=getchar())!='0'){
        int count=1;
        int dp1=1,dp2=1;
        while((tmp=getchar())!='\n'){
            if(head=='0'||head>'2'||(head=='2'&&tmp>'6'))
				dp1=dp2;
            else if(tmp=='0'){
				dp1=dp1+dp2;
				dp2=dp1-dp2;
				dp1=dp1-dp2;
			}
            else{
				dp2=dp1+dp2;
				dp1=dp2-dp1;
			}
            head=tmp;
        }
        cout<<dp2<<"\n";
    }
    return 0;
}
