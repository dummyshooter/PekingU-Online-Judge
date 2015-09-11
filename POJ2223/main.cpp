#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 10e-8
using namespace std;

char buff[10],map[32][32];
int i,N;
double vx[11],vy[11],vz[11];

int main()
{
	while(scanf("%s%d",buff,&N)!=EOF){
		memset(map,0,sizeof(map));
		for(i=0;i<=N;i++){
			scanf("%lf,%lf,%lf",&vz[i],&vx[i],&vy[i]);
			if(i){vz[i]-=vz[0]; vx[i]-=vx[0];  vy[i]-=vy[0];}
		}
		getchar();
		int width=0,height=0;
		for(i=0;;i++){
			gets(map[i]);
			int len=strlen(map[i]);
			if(!strcmp(map[i],"END"))
				break;
			if(len>width)
				width=len;
			height++;
		}
		bool flag=false;
		for(i=1;i<=N;i++){
			if(vz[i]<INF)
				continue;
			double fx=10.0*width/2.0+1000.0/vz[i]*vx[i];
			double fy=10.0*height/2.0+1000.0/vz[i]*vy[i];
			if(fy<INF||fy>10*height||fx<INF||fx>10*width)
				continue;
			int ix=(int)(fx/10),iy=height-(int)(fy/10)-1;
			if(map[iy][ix]&&map[iy][ix]!=' '){
				map[iy][ix]='*'; flag=true;
			}
		}
		if(flag){
			for(i=0;i<height;i++)
				printf("%s\n",map[i]);
		}
		else
			printf("Got Out Da Way!\n");
		printf("\n");
	}
	return 0;
}
