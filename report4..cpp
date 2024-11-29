#include "stdio.h"
#include "iostream"
using namespace std;

struct Link
{
    int Data;
    Link* Next;
};

Link* createLink()
{
    int num=0;
    Link* head;
    Link* p;
    Link* q;
    head=(Link*)malloc(sizeof(Link));
    head->Next=NULL;
    q=head;
    cout<<"你要输入多少个数据？";
    cin>>num;
    for(int i=1;i<=num;i++)
        {
            p=q;
            q=(Link*)malloc(sizeof(Link));
            p->Next=q;
            cout<<"请输入该链表中的数据。";
            cin>>q->Data;
        }
    q->Next=NULL;
    return head;
}

Link* insert(Link* head)
{
    int num=0;
    Link* p=head;
    Link* q;
    cout<<"你要在第几个数据后插入数据。";
    cin>>num;
    for(int i=1;i<=num;i++,p=p->Next)
        {
            if(p==NULL)
                {
                    cout<<"数字过大，超出范围！";
                    break;
                }
        }
    
    q=(Link*)malloc(sizeof(Link));
    q->Next=p->Next;
    p->Next=q;
    cin>>q->Data;
    return head;
}

void show(Link* head)
{
    cout<<endl;
    for(Link* p=head->Next;p!=NULL;p=p->Next)
        {
            cout<<p->Data<<"   ";
        }
}

void Ex(Link* head,int min,int max)
    {
        Link *p,*q,*r;
        q=head;
        p=head->Next;
        while(p && p->Data<=min)
            {
                q=p;p=p->Next;
            }
        while(p && p->Data<max)
            {
                r=p;p=p->Next;free(r);
            }
        q->Next=p;
    }

Link* delete0(Link *head)
{
    int num;
    Link* p;
    Link* q;
    p=head;
    cout<<"请你输出要删除的是第几个位置的数据。";
    cin>>num;
    if(num<1)
        {cout<<"必须数字大于1！";
        return head;}
    for(int i=1;i<num;i++,p=p->Next);
    q=p->Next;
    p->Next=q->Next;
    free(q);
    return head;
}

Link* createLink2()
    {
    int num=0;
    Link* head;
    Link* q;
    head=(Link*)malloc(sizeof(Link));
    head->Next=NULL;
    q=head;
    cout<<"你要输入多少个数据？";
    cin>>num;
    for(int i=1;i<=num;i++)
        {
            q=(Link*)malloc(sizeof(Link));
            q->Next=head->Next;
            head->Next=q;
            cout<<"请输入该链表的数据。";
            cin>>q->Data;
        }    
    return head;
    }

void Tp(Link* head)
    {
        Link *p,*q,*r;
        for(p=head;p;p=p->Next)
            {
                for(q=p,r=q->Next;r;r=q->Next)
                    {
                        if(r->Data!=p->Data)
                            {q=r;}
                        else
                            {
                                q->Next=r->Next;free(r);
                            }
                    }
            }
    }

int main()
{
    Link* p;
    Link* q;
    p=createLink();   
    show(p);
    Tp(p);
    show(p);
}

