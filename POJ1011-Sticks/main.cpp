#include <iostream>
#include <algorithm>
#include <string.h>

int len[65];
int hash[65];
int num;
int lps,k;

bool search(int,int,int,int);
int cmp(const void*,const void*);

using namespace std;
int main()
{
    int i,j;

    while((cin>>num)&&num){
        int sum=0;
        for(i=1;i<=num;i++){
            cin>>len[i];
            sum+=len[i];
        }
        qsort(len+1,num,sizeof(int),cmp);


        for(j=len[1];j<=sum;j++)
            if(sum%j==0){
                memset(hash,0,sizeof(int)*65);
                k=sum/j;
                lps=j;
                if(search(0,0,0,1)){
                    cout<<lps<<"\n";
                    break;
                }
            }
        }

   return 0;
}

int cmp(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}

bool search(int prevlen,int numcompleted,int numused,int prevsign)
{
    int i,tmp=0;
    bool sign=false;

    if(numcompleted==k&&numused==num)
        return true;

    for(i=prevsign;i<=num;i++)
        if(!hash[i]&&(prevlen+len[i])<=lps&&len[i]!=tmp){
            tmp=len[i];
            hash[i]=1;
            if((prevlen+len[i])==lps)
                sign=search(0,numcompleted+1,numused+1,1);
            else
                sign=search(prevlen+len[i],numcompleted,numused+1,i+1);

            if(sign)
                return true;
            else if(prevsign==1){
                hash[i]=0;
                return false;
            }
            else{
                hash[i]=0;
                continue;
                }
            }


    return sign;
}
