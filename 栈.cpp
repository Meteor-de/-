#include "stdio.h"
#include "iostream"
using namespace std;

struct stack
{
    int* data;
    int capicity;
    int top;
};

void InitStack(stack &s)
    {
        free(s.data);
        s.data=(int*)malloc(sizeof(int)*6);
        s.capicity=6;
        s.top=0;
    }

void DestroyStack(stack &s)
    {
        free(s.data);
        s.capicity=0;
        s.top=0;
    }

bool StackEmpty(stack s)
    {
        if(s.capicity==0)
            cout<<"这是一个已销毁的栈。";
        return s.top==0;
    }


int StackLength(stack s)
    {
        return s.top;
    }

void GetTop(stack s,int &e)
    {
        if(StackEmpty(s))
            cout<<"error!";
        e=s.data[s.top-1];
    }

void ClearStack(stack &s)
    {
        free(s.data);
        s.top=s.capicity=0;
    }

void push(stack &s,int e)
    {
        if(s.capicity==s.top)
            {
                s.data=(int*)realloc(s.data,sizeof(int)*(s.capicity+=6));
                s.capicity+=6;
            }
        s.data[s.top+1]=e;
        s.top+=1;
    }

void pop(stack &s,int &e)
    {
        e=s.data[s.top];
        s.top-=1;
    }

void Conversion()
    {
        stack s;
        int N;
        int n;
        InitStack(s);
        cout<<"你要转换的数字。"<<endl;
        cin>>N;
        cout<<endl<<"你要转换的进制。"<<endl;
        cin>>n;
        cout<<endl;
        while(N)
            {
                push(s,N%n);
                N=N/n;
            }
        while(!StackEmpty(s))
        {
            int e;
            pop(s,e);
            cout<<e;
        }
        

    }

int main()
{
    Conversion();
}