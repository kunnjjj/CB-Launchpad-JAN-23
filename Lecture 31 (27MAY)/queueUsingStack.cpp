#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    stack<int> s;
    public:

    void insertAtBottom(stack<int> &s,int spl_ele)
    {
        if(s.empty())
        {
            s.push(spl_ele);
            return ;
        }

        int x=s.top();
        s.pop();
        insertAtBottom(s,spl_ele);
        s.push(x);
    }

    void push(int x)
    {
        insertAtBottom(s,x);
    }

    void pop()
    {
        if(s.empty())
        {
            cout<<"underflow"<<endl;
            return ;
        }
        s.pop();
    }

    int front()
    {
        if(s.empty())
        {
            cout<<"underflow"<<endl;
            return -1;
        }

        return s.top();
    }
};
int main()
{


    return 0;
}