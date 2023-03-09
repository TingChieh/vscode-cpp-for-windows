#include <iostream>
#include <stdlib.h>
#include <iostream>
#define ok 1
#define error 2
#define n 1000
typedef int status;
typedef int elemtype;
using namespace std;

typedef struct Lnode
{
    elemtype data;
    struct Lnode *next;
}Lnode, *linklist;

status Initlist(linklist &L)
{
    L=new Lnode;
    L->next=NULL;
    return ok;
}

status getelem(linklist L, int i, elemtype &e)
{
    int p=L->next;
    int j=1;
    while(p&&j<i)
    {

        p=p->next;
        ++j;
    }
    if(!p||j>i) return error;
    e=p->data;
    return ok;
}

status listinsert(linklist &L, int i, elemtype e)
{
    int p=L, j=0;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(p||j>i-1) return error;
    s=new Lnode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return ok;
}

int main()
{
    linklist L;
    Initlist(L);
    int i=0, x;
    while(1)
    {
        cin>>x;
        listinsert(L, i, x);
        if(x==-1) break;
        i++;
    }
    for(int j=i;j>0;j--)
    {
        cout<<L.data[j]<<' ';
    }
    return 0;
}