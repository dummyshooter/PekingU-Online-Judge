#include <iostream>
#include <cstring>
#include <cstdio>

long fa[60000];
long rel[60000];
long n;
long eat;

long findf(long k);

int main()
{
    long sum=0,a,b,c,s,k;
    memset(fa,0,sizeof(fa));
    scanf("%ld%ld",&n,&k);
    while(k--){
        scanf("%ld%ld%ld",&a,&b,&c);
        if(a==1){
            if(b>n||c>n){
                sum++;
                continue;
                }
            if(findf(b)==findf(c)&&rel[c]==rel[b])
                continue;
            if(findf(b)!=findf(c)){
                s=findf(c);
                fa[s]=b;
                rel[s]=-rel[c];
                continue;
            }
            sum++;
        }
        else{
            if(b>n||c>n||b==c){
                sum++;
                continue;
                }
            if(findf(b)==findf(c)){
                if(rel[b]==1&&rel[c]==0)
                    continue;
                if(rel[b]==0&&rel[c]==-1)
                    continue;
                if(rel[b]==-1&&rel[c]==1)
                    continue;
                }
            if(findf(b)!=findf(c)){
                s=findf(c);
                fa[s]=b;
                if(rel[c]==0)
                    rel[s]=-1;
                if(rel[c]==1)
                    rel[s]=1;
                if(rel[c]==-1)
                    rel[s]==0;
                continue;
                }
            sum++;
            }
        }
    printf("%ld\n",sum);
    return 0;
}

long findf(long k)
{
    if(fa[k]==0){
        eat=0;
        return k;
        }
    else{
        long s=findf(fa[k]);
        eat+=rel[k];
        if(eat==2)
            eat=-1;
        if(eat==-2)
            eat=1;
        rel[k]=eat;
        return fa[k]=s;
    }
}
