#include <iostream>
#include <cstring>
#define MAXIUM 28

int hash[MAXIUM];
int stack[MAXIUM][MAXIUM];
int stackp[MAXIUM]={0};
int N;

void init();
void moveonto(int ins,int pos);
void moveover(int ins,int pos);
void pileonto(int ins,int pos);
void pileover(int ins,int pos);
void clear(int ins);
void putback(int ins);

using namespace std;
int main()
{
    char ins1[5]="move",pos1[5]="onto";
    char end[5]="quit";
    char op1[5],op2[5];

    cin>>N;
    init();
    while(cin>>op1&&strcmp(op1,end)){
        int ins,pos;
        cin>>ins>>op2>>pos;
        if(!strcmp(op1,ins1)){
            if(!strcmp(op2,pos1))
                moveonto(ins,pos);
            else
                moveover(ins,pos);
        }
        else{
            if(!strcmp(op2,pos1))
                pileonto(ins,pos);
            else
                pileover(ins,pos);
        }
    }
   for(int i=0;i<N;i++){
       cout<<i<<":";
       int j;
       for(j=0;j<stackp[i];j++)
            cout<<' '<<stack[i][j];
       cout<<"\n";
   }
   return 0;
}

void init()
{
    for(int i=0;i<N;i++){
        stack[i][stackp[i]++]=i;
        hash[i]=i;
    }
    return;
}

void moveonto(int ins,int pos)
{
    int p1=hash[ins],p2=hash[pos];

    if(p1==p2)
        return;

    clear(ins);
    clear(pos);
    stack[p2][stackp[p2]++]=ins;
	hash[ins]=p2;
    stackp[p1]--;

    return;
}

void moveover(int ins,int pos)
{
    int p1=hash[ins],p2=hash[pos];

    if(p1==p2)
        return;

    clear(ins);
    stack[p2][stackp[p2]++]=ins;
    hash[ins]=p2;
    stackp[p1]--;

    return;
}

void pileonto(int ins,int pos)
{
    int p1=hash[ins],p2=hash[pos];

    if(p1==p2)
        return;

    clear(pos);
    int i=0;
    while(stack[p1][i]!=ins)
        i++;
	int tmp=stackp[p1];
    for(;i<tmp;i++){
        stack[p2][stackp[p2]++]=stack[p1][i];
        hash[stack[p1][i]]=p2;
        stackp[p1]--;
    }
    return;
}

void pileover(int ins,int pos)
{
    int p1=hash[ins],p2=hash[pos];

    if(p1==p2)
        return;
    int i=0;
    while(stack[p1][i]!=ins)
        i++;
	int tmp=stackp[p1];
    for(;i<tmp;i++){
        stack[p2][stackp[p2]++]=stack[p1][i];
        hash[stack[p1][i]]=p2;
        stackp[p1]--;
    }

    return;
}

void clear(int ins)
{
    int p1=hash[ins];
    int i=stackp[p1]-1;

    while(stack[p1][i]!=ins){
        putback(stack[p1][i]);
        i--;
        stackp[p1]--;
    }
    return;
}

void putback(int ins)
{
    stack[ins][stackp[ins]++]=ins;
    hash[ins]=ins;
}
