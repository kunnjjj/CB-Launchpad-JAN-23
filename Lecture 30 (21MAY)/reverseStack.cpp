#include<iostream> 
#include<stack>
using namespace std; 


void transferStack(stack<int> &A,stack<int> &B)
{
    while(!A.empty())
    {
        int x=A.top();
        B.push(x);
        A.pop();
    }
}

void reverseStack(stack<int> &s)
{
    stack<int> aux1;
    stack<int> aux2;

    // while(!s.empty())
    // {
    //     int x=s.top();
    //     s.pop();
    //     aux1.push(x);
    // }
    transferStack(s,aux1);

    // while(!aux1.empty())
    // {

    //     int x=aux1.top();
    //     aux1.pop();
    //     aux2.push(x);
    // }
    transferStack(aux1,aux2);

    // while(!aux2.empty())
    // {
    //     int x=aux2.top();
    //     aux2.pop();
    //     s.push(x);
    // }

    transferStack(aux2,s);

}

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}


void insertAtBottom(stack<int> &s,int spl_ele)
{
    if(s.empty())
    {
        // TODO
        s.push(spl_ele);
        return ;
    }

    int x=s.top();
    s.pop();
    insertAtBottom(s,spl_ele);
    s.push(x);
}

void reverseStackUsingRecursion(stack<int> &s)
{
    if(s.empty())
    {
        return ;
    }

    int x=s.top();
    s.pop();
    reverseStackUsingRecursion(s);
    insertAtBottom(s,x);
}

int main()
{   
    stack<int> s;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        s.push(x);
    }

    printStack(s);

    reverseStack(s);

    printStack(s);

    return 0;
}