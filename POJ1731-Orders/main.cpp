#include <stdio.h>
#include <string.h>
#include <algorithm.h>

using namespace std;

qsort(char *,int,int);

int main()
{
	char buff[201];
	int length;
	
	gets(buff);
	length=strlen(buff);
	qsort(buff,0,length-1);

	char *first=buff;
	char *last=buff+strlen(buff);

	do{
		printf("%s\n",buff);
	 }
	while(next_permutation(first,last));

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





