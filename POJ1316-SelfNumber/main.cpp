#include <iostream>

using namespace std;

int main()
{
    int hash[10000]={0};
    int i,tmp;

    for(i=1;i<10;i++){
        tmp=i*2;
        if(!hash[tmp])
            hash[tmp]=1;
    }

    for(i=10;i<100;i++){
        tmp=i+i/10+i%10;
        if(!hash[tmp])
            hash[tmp]=1;
    }

    for(i=100;i<1000;i++){
        tmp=i+i/100+(i/10)%10+i%10;
         if(!hash[tmp])
            hash[tmp]=1;
    }

    for(i=1000;i<10000;i++){
        tmp=i+i/1000+i%10+(i/10)%10+(i/100)%10;
        if(tmp<10000)
            if(!hash[tmp])
                hash[tmp]=1;
    }

    for(i=1;i<10000;i++){
         if(!hash[i])
            cout<<i<<"\n";
    }

    return 0;
}
