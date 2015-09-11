#include <iostream>
using namespace std;
int main()
{
    int N;
    int seq[100]={0};

    cin>>N;
    seq[1]=1;
    for(int i=2;i<=N;i++){
        int tmp;
        cin>>tmp;
        seq[i]=tmp+1;
        for(int j=1;j<=N;j++)
            if(seq[j]>tmp)
                seq[j]++;
    }
    for(int i=1;i<=N;i++)
        cout<<seq[i]<<"\n";
    return 0;
}
