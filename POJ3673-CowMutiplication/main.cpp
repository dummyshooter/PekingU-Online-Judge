#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char s1[15],s2[15],tmp;
    int c1=0,c2=0,i,j;
    long long sum=0;

    while((tmp=getchar())!=' ')
        s1[c1++]=tmp;
    while((tmp=getchar())!='\n')
        s2[c2++]=tmp;

    for(i=0;i<c1;i++)
        for(j=0;j<c2;j++)
            sum+=(s1[i]-48)*(s2[j]-48);

    cout<<sum<<'\n';
    return 0;
}
