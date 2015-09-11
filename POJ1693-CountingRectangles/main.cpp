#include <iostream>
#include <cstring>

typedef struct seg
{
    int ax,ay,bx,by;
}
segment;

void swap(int *a,int *b);

using namespace std;
int main()
{
    int casenum,N,i,j,m,n;
    segment tmp;
    segment vertical[105];
    segment parallel[105];
    int vernum;
    int panum;

    cin>>casenum;
    while(casenum-->0){
        int count=0;
        memset(vertical,0,sizeof(vertical));
        memset(parallel,0,sizeof(parallel));
        vernum=panum=1;
        cin>>N;
        for(i=1;i<=N;i++){
            cin>>tmp.ax>>tmp.ay>>tmp.bx>>tmp.by;
            if(tmp.ax==tmp.bx){
                if(tmp.ay<tmp.by)
                    swap(tmp.ay,tmp.by);
                vertical[vernum++]=tmp;
            }
            else if(tmp.ay==tmp.by){
                if(tmp.ax<tmp.bx)
                    swap(tmp.ax,tmp.bx);
                parallel[panum++]=tmp;
            }
        }
        for(i=2;i<vernum;i++)
            for(j=1;j<i;j++)
                for(m=2;m<panum;m++)
                    for(n=1;n<m;n++){
                        if(max(parallel[m].ay,parallel[n].ay)<min(vertical[i].ay,vertical[j].ay)
                        && min(parallel[m].by,parallel[n].by)>max(vertical[i].by,vertical[j].by)
                        && max(vertical[i].ax,vertical[j].ax)<min(parallel[m].ax,parallel[n].ax)
                        && min(vertical[i].bx,vertical[j].bx)>max(parallel[m].bx,parallel[n].bx))
                            count++;
                    }
        cout<<count<<'\n';
        }
    return 0;
}

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
