#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int cmp(const void*,const void*);

int main()
{
    int i,j,N,M;
    int seq[55];
    int hash[1005];
	int casenum=0;

    while((cin>>N>>M)&&(N||M)){
		casenum++;
		memset(hash,0,sizeof(int)*1005);
        for(i=1;i<=M;i++)
            cin>>seq[i];
        qsort(seq+1,M,sizeof(int),cmp);
        for(i=1;i<=M;i++)
            hash[seq[i]]=1;
        for(i=1;i<=M;i++){
			int sign=0;
            for(j=seq[i]+1;j<=N*M;j++)
                if(!hash[j]){
                    hash[j]=1;
                    sign=1;
                    break;
                }
            if(!sign)
                break;
        }
        cout<<"Case "<<casenum<<": "<<(M-i+1)<<"\n";
    }

     return 0;
}

int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}
