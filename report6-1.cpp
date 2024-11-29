#include "iostream"
using namespace std;

int time=1;
void move(char pos1,char pos2)
    {
        cout<<"第"<<time<<"次"<<pos1<<"移动到了"<<pos2<<endl;
        time++;
    }

void hanoi(int n,char pos1,char pos2,char pos3)
    {
        if(n==1) move(pos1,pos3);
        else
            {
                hanoi(n-1,pos1,pos3,pos2);
                move(pos1,pos3);
                hanoi(n-1,pos2,pos1,pos3);
            }
    }

int main()
{
    int n;
    cin>>n;
    cout<<endl;
    hanoi(n,'A','B','C');
    return 0;
}