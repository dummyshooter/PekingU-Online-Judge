#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair <int,long long> PAIR;
int q_num[1050];
struct cmp{
	bool operator()(const PAIR &a,const PAIR &b){
		if(a.second>b.second)
			return true;
		else if(a.second==b.second&&q_num[a.first]>q_num[b.first])
			return true;
		else
			return false;
	}
};
priority_queue <PAIR,vector<PAIR>,cmp> q;

int main()
{
	char ins[10];
	int K,count=0;
	long long time[1050];

	while(scanf("%s",ins)&&strcmp(ins,"#")){
		scanf("%d%I64d",&q_num[count],&time[count]);
		q.push(make_pair(count,time[count]));
		count++;
	}
	cin>>K;
	while(K--){
		PAIR tmp=q.top(); q.pop();
		printf("%d\n",q_num[tmp.first]);
		q.push(make_pair(tmp.first,tmp.second+time[tmp.first]));
	}
	return 1;
}
