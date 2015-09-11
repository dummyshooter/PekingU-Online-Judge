#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    const double key=(1+sqrt(5.0))/2.0;
    int a,b;

    while(cin>>a&&cin>>b){
        if(a>b){
            int tmp=b;
            b=a;
            a=tmp;
        }
        int cap=b-a;
        if(a==(int)(cap*key))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    return 0;
}
