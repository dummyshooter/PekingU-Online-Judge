#include <iostream>
#include <cstring>
char s1[205],s2[205],s3[415];
int l1,l2,l3;
int sign;

void dfs(int,int,int);

using namespace std;
int main()
{
    int casenum;

    cin>>casenum;
    for(int i=1;i<=casenum;i++){
        sign=0;
        cin>>s1>>s2>>s3;
        l1=strlen(s1);
        l2=strlen(s2);
        l3=strlen(s3);
        if((l3!=l1+l2)||((s3[l3-1]!=s1[l1-1])&&(s3[l3-1]!=s2[l2-1])))
            ;
        else
            dfs(0,0,0);

        cout<<"Data set "<<i<<": ";
        if(sign)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }

    return 0;
}

void dfs(int a,int b,int c)
{
    if(c>=l3){
        sign=1;
		return;
	}
	if(sign)
		return;
    if(a<l1&&s1[a]!=s3[c]&&b>=l2)
        return;
    if(b<l2&&s2[b]!=s3[c]&&a>=l1)
        return;
    if(a<l1&&s1[a]!=s3[c]&&b<l2&&s2[b]!=s3[c])
        return;
    if(a<l1&&s1[a]==s3[c])
        dfs(a+1,b,c+1);
    if(b<l2&&s2[b]==s3[c])
        dfs(a,b+1,c+1);
}




