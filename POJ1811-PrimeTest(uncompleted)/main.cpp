#include <iostream>
#include <math.h>
using namespace std;

long SQUFOF(long long N,int k);
long long gcd(long long a,long long b);

int main()
{
    int casenum;
    long long N;

    cin>>casenum;
    while(casenum--){
        cin>>N;
        cout<<SQUFOF(N,1)<<'\n';
    }
    return 0;
}

long SQUFOF(long long N,int k)
{
    double p[3],q[3];
    double tmp=N,b;
    double tmp_=(long long)sqrt(k*tmp);

    p[0]=tmp_;
    q[0]=1.0;
    q[1]=k*N-p[0]*p[0];

    long long test=5;

    while(test%((long long)sqrt(test))!=0){
        b=(long long)((tmp_+p[0])/q[1]);
        p[1]=b*q[1]-p[0];
        q[2]=q[0]+b*(p[0]-p[1]);
        q[0]=q[1],q[1]=q[2],p[0]=p[1];
        test=q[1];
    }

    b=(long long)((tmp_-p[1])/(sqrt(q[1])));
    p[0]=b*sqrt(q[1])+p[1];
    q[0]=sqrt(q[1]);
    q[1]=(k*tmp-p[0]*p[0])/q[0];

    while(1){
        b=(long long)((tmp_+p[0])/q[1]);
        p[1]=b*q[1]-p[0];
        q[2]=q[0]+b*(p[0]-p[1]);
        q[0]=q[1],q[1]=q[2];
        if(p[0]==p[1])
            break;
        else
            p[0]=p[1];
    }

    int f=gcd(N/k,(long long)p[0]);

    return f;
}

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
