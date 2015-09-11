#include <iostream>

int L,C;
char path[26];
char a[26];
char list[256];

void dfs(int i,int v,int k);

using namespace std;
int main()
{
    int i,j;
    char str[8];

    cin>>L>>C;
    for(i=0;i<C;i++){
        cin>>str;
        list[str[0]]++;
    }
    j=0;
    for(i='a';i<='z';i++)
        if(list[i])
            a[j++]=i;
    path[L]=0;
    dfs(0,0,0);

    return 0;
}

void dfs(int i,int v,int k)
{
    if(k==L){
        if(v)
            printf("%s\n",path);
        return;
    }
    for(;i<=C-L+k;i++){
        path[k]=a[i];
        dfs(i+1,v+(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'),k+1);
    }
}

