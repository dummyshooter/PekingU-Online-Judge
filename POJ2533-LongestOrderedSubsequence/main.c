#include <stdio.h>

main()
{
	int seq[1000];
	int f[1000];
	int num[1000];
	int sign,tmp;
	int i,j,N;

	scanf("%d",&N);

	for(i=0;i<N;i++)
		scanf("%d",&seq[i]);

	f[0]=seq[0];
	num[0]=1;

	for(i=1;i<N;i++){
		tmp=2;
		sign=1;
		for(j=0;j<i;j++)
			if(seq[i]>f[j]&&num[j]>=tmp-1){
					tmp=num[j]+1;
					sign=0;
					}
		if(tmp<=num[i-1])
			sign=1;
		if(sign){
			f[i]=f[i-1];
			num[i]=num[i-1];
			}
		else{
			f[i]=seq[i];
			num[i]=tmp;
		}

	}

	printf("%d\n",num[N-1]);
}                                  
