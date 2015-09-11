#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int casenum;
    double tmp_double;
    unsigned long long seqnum,tmp;

    cin>>casenum;
    while(casenum-->0){
        cin>>seqnum;
        tmp_double=2*seqnum;
        tmp=sqrt(tmp_double);
        while(tmp*(tmp+1)/2>seqnum)
            tmp--;
		if(seqnum-tmp*(tmp+1)/2)
			tmp=seqnum-tmp*(tmp+1)/2;

        cout<<tmp<<"\n";
    }
    return 0;
}
