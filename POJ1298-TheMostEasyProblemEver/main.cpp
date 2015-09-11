#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXIUM 5000
using namespace std;
int main()
{
    char start[6]="START";
    char end[4]="END";
    char out[11]="ENDOFINPUT";
    char buff[MAXIUM];

    while(1){
        gets(buff);
        if(!strcmp(buff,out))
            break;
        else if(!strcmp(buff,start)){
            gets(buff);
            int i=0;
            while(buff[i]!='\0'){
                if(buff[i]<'A'||buff[i]>'Z')
                    printf("%c",buff[i]);
                else if(buff[i]+21>'Z')
                    printf("%c",buff[i]-5);
                else
                    printf("%c",buff[i]+21);
                i++;
            }
            printf("\n");
        }
        else if(!strcmp(buff,end))
            ;
    }
    return 0;
}



