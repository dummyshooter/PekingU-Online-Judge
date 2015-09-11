#include <stdio.h>
#include <string.h>

qsort(char *,int,int);
swap(char *,char *);
output(char [], int);

char tmp[201];

int main()
{
	char buff[201];
	int length;
	
	gets(buff);
	length=strlen(buff);
	qsort(buff,0,length-1);

	output(buff,length); 
	return 0;
}

qsort(char *a,int left,int right)
{
    int i,j;
    char k,mid;
    i=left;
    j=right;
    mid=a[(left+right)/2];
    while(i<=j)
    {
        while(a[i]<mid)
            i++;
        while(a[j]>mid)
            j--;
        if(i<=j)
        {
            k=a[i];
            a[i]=a[j];
            a[j]=k;
            i++;
            j--;
        }
    }
    if(i<right)
        qsort(a,i,right);
    if(j>left)
        qsort(a,left,j);
 
}

swap(char *a,char *b)
{
	char tmp;

	tmp=*a;
	*a=*b;
	*b=tmp;
}
 		
output(char list[],int length) 
{
	char tmp;
	int sign=0;
	int i,j;

	while(1){
		sign=0;
		for(i=length-1;i>0;i++)
			if(list[i-1]<list[i]){
				sign=1;
				break;
			}
		if(!sign)
			break;
		i-=1;
		tmp=list[i];
		for(j=0;j<i;j++)
			if(list[j]>tmp)
				break;
		swap(&list[i],&list[j]);
		qsort(list,i+1,length-1);
		printf("%s\n",list);
	}
}


