#include <iostream>
#include <cstdio>
#include <math.h>
#define PI (3.1415926)
using namespace std;
int main()
{
    int D,V;

    while(cin>>D>>V&&(D||V)){
        double tmp=V;
        double d=D*D*D;
        d-=6*tmp/PI;
        tmp=((double)1)/3;
        d=pow(d,tmp);
        printf("%.3f\n",d);
    }
    return 0;
}

