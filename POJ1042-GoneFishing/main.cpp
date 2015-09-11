#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    int n,h,i,j,num;
    int f[30],d[30],t[30];
    int tmpf[30],tmpd[30];
    int sum[30],time[30][30];

    while((cin>>n)&&n){
        memset(t,0,sizeof(int)*30);
        memset(sum,0,sizeof(int)*30);
        memset(time,0,sizeof(int)*30*30);
        cin>>h;
        h*=12;
        for(i=1;i<=n;i++)
            cin>>f[i];
        for(i=1;i<=n;i++)
            cin>>d[i];
        for(i=1;i<=n-1;i++){
            cin>>t[i];
            t[i]+=t[i-1];
        }
        for(i=1;i<=n;i++){
            if((num=h-t[i-1])<0)
                break;

			for(j=1;j<=i;j++){
                tmpf[j]=f[j];
                tmpd[j]=d[j];
            }

			while(num>0){
				int tmp=-1,tmp_=0;
				for(j=1;j<=i;j++)
					if(tmpf[j]>tmp){
						tmp=tmpf[j];
						tmp_=j;
					}

				sum[i]+=tmpf[tmp_];
				time[i][tmp_]++;

				if((tmp-tmpd[tmp_])>=0)
                    tmpf[tmp_]-=tmpd[tmp_];
                else
                    tmpf[tmp_]=0;


                num--;
            }
        }

		int max=-1,lakenum;
		for(i=1;i<=n;i++)
            if(sum[i]>max){
				lakenum=i;
                max=sum[i];
			}

        for(i=1;i<=n-1;i++)
            cout<<5*time[lakenum][i]<<", ";
        cout<<5*time[lakenum][i]<<"\n";

        cout<<"Number of fish expected: "<<max<<"\n\n";
    }

     return 0;
}



