#include "stdio.h"
#include "iostream"
#include "string.h"
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

void pop(stack &s,char &e)
    {
        e=s.data[s.top];
        s.top-=1;
    }

bool Conversion()
    {
        stack s;
        char e1;
        char e2;
        char exp[100];
        gets(exp);
        InitStack(s);
        for(int i=0;i<strlen(exp);i++)
            {
                if(exp[i]=='(' || exp[i]==')' || exp[i]=='[' || exp[i]==']'|| exp[i]=='{'|| exp[i]=='}')
                    {
                        push(s,exp[i]);
                    }
            }
        if(s.top%2!=0)
            return false;
        while(!StackEmpty(s))
            {

                bool flag=false;
                pop(s,e1);
                pop(s,e2);
                if( (e1==')' && e2=='(') || (e1=='}' && e2=='{') || (e1==']' && e2=='[')) 
                    {
                        flag=true;
                    }
                else
                    {
                        return false;
                    }
                return flag;
            }
        

    }

int main()
{
    if(Conversion())
        {
            cout<<"true";    
        }
    else
            cout<<"false";
    return 0;
}