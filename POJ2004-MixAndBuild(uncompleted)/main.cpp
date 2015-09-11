#include <iostream>
#include <cstring>
#include <cstdio>
#define NIL 999

char s[10050][25];
short in[10050];
short out[10050];
short seq[10050];
short edge[100000000][2];
int sum;
int tmpmax=0;
int edgenum=0;

void proc(int a,int b,int len);
void BellmanFord(int s);

using namespace std;
int main()
{
    short length[10005];
    int i=1,j;

    while(scanf("%s",&s[i])!=EOF){
        length[i]=strlen(s[i]);
		i++;
	}
    sum=i-1;

	if(sum==1){
		cout<<s[1]<<'\n';
		return 0;
	}

    for(i=2;i<=sum;i++)
        for(j=1;j<i;j++){
            if(length[i]-length[j]==1)
                proc(i,j,length[i]);
            else if(length[j]-length[i]==1)
                proc(j,i,length[j]);
        }

    for(i=1;i<=sum;i++)
        if(out[i]&&!in[i])
            BellmanFord(i);

    for(i=0;i<=tmpmax;i++)
        printf("%s\n",s[seq[i]]);

	return 0;
}

void proc(int a,int b,int len)
{
	short ha1[26]={0},ha2[26]={0};
	short i;

    for(i=0;i<len-1;i++){
        ha1[s[a][i]-'a']++;
		ha2[s[b][i]-'a']++;
	}
	ha1[s[a][i]-'a']++;

	for(i=0;i<26;i++)
		if(ha1[i]<ha2[i])
			return;

	edge[edgenum][0]=b;
	edge[edgenum++][1]=a;
	out[b]++;
	in[a]++;
    return;
}

void BellmanFord(int s)
{
	int i,tmp=0;
    short dist[10005];
    short path[10005]={0};
    bool relaxed;

	for(i=0;i<=sum;i++)
		dist[i]=NIL;
    dist[s]=0;
    for(i=1;i<=sum-1; ++i){
        relaxed=false;
        for(int j=0;j<edgenum;j++)
            if((dist[edge[j][0]]!=NIL)&&(dist[edge[j][1]]>dist[edge[j][0]]-1)){
                dist[edge[j][1]]=dist[edge[j][0]]-1;
				if(dist[edge[j][1]]<tmp)
					tmp=dist[edge[j][1]];
                path[edge[j][0]]=edge[j][1];
                relaxed=true;
            }
        if(!relaxed)
            break;
    }
    if(tmp+tmpmax<0){
        tmpmax=tmp*(-1);
        int ptr=s;
        for(int i=0;i<=tmpmax;i++){
            seq[i]=ptr;
            ptr=path[ptr];
        }
    }
}

