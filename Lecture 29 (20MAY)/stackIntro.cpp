#include<iostream>
using namespace std;

template <typename T1>
class Node
{
    public:
    T1 data;
    Node* next;
    Node(T1 data)
    {
        this->data=data;
        next=NULL;
    }
};



template <typename TYPE>
class Stack
{
    Node<TYPE>* head;
    int curSize;
    public:
    Stack()
    {
        head=NULL;
        curSize=0;
    }
    
    void push(TYPE d)
    {
        Node<TYPE>* nayaNode=new Node<TYPE>(d);
        nayaNode->next=head;
        head=nayaNode;
        curSize++;
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"Underflow"<<endl;
            return ;
        }
        curSize--;
        Node<TYPE>* temp=head->next;
        delete(head);
        head=temp;
    }

    TYPE top()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            TYPE T;
            return T;
        }   
        return head->data;
    }

    int size()
    {
        return curSize;
    }

    bool isempty()
    {
        return curSize==0;
    }
};

int main()
{
    

    // vector<int> v;
    // vector<string> v1;
    // vector<int> v;
    // vector<char> v;
    Stack<int> stack;
    stack.push(4);
    stack.push(5);
    cout<<stack.top()<<endl;
    stack.push(7);
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    cout<<stack.size()<<endl;
    // cout<<"true"<<endl;
    bool x=true;
    if(x)
    {
        cout<<"true"<<endl;
    }

    cout<<boolalpha<<x<<endl;

    Stack<char> s;
    s.push('c');
    cout<<s.top()<<endl;
    return 0;
}