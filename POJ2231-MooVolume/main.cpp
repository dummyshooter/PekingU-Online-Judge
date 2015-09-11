#include <iostream>
#include <cstdlib>
#define MAXIUM 10050
using namespace std;
int main()
{
    int N;
    int pos[MAXIUM]={0};
    long long sum=0;

    cin>>N;
    for(int i=1;i<=N;i++){
        scanf("%d",&pos[i]);
        for(int j=1;j<i;j++)
            sum+=abs(pos[i]-pos[j]);
    }
    cout<<2*sum<<"\n";
    return 0;
}
