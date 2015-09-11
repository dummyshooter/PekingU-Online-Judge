#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int main()
{
    short hash[1000050]={0};
	short list[105][10][3];
	short count[105]={0};
	bool ha[105]={false};
    int i,j,k,N;

    cin>>N;
    for(i=6;i<=N;i++)
        hash[i*i*i]=i;

	int k1=(int)pow((double)(N*N*N/3),1.0/3)+1;
	int k2=(int)pow((double)(N*N*N/2),1.0/3)+1;

    for(i=2;i<=k1;i++)
        for(j=i;j<=k2;j++)
            for(k=j;k<=N;k++){
                int tmp=i*i*i+j*j*j+k*k*k;
                if(tmp>N*N*N)
                    break;
                else if(hash[tmp]!=0){
						int p=hash[tmp];
						ha[p]=true;
						list[p][count[p]][0]=i;
						list[p][count[p]][1]=j;
						list[p][count[p]++][2]=k;
				}
            }

	for(i=6;i<=N;i++)
		if(ha[i])
			for(int v=0;v<count[i];v++)
				printf("Cube = %d, Triple = (%d,%d,%d)\n",i,list[i][v][0],list[i][v][1],list[i][v][2]);

    return 0;
}
