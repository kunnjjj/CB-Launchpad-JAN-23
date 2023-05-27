#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d)
    {
        next=NULL;
        prev=NULL;
        data=d;
    }
};  

class Deque
{
    Node* fakeHead;
    Node* fakeTail; 
    int curSize;
    public:
    Deque()
    {
        fakeHead=new Node('\0');
        fakeTail=new Node('\0');
        fakeHead->next=fakeTail;
        fakeTail->prev=fakeHead;
        curSize=0;
    }

    void push_front(int x)
    {
        Node* nayaNode=new Node(x);
        Node* temp=fakeHead->next;

        fakeHead->next=nayaNode;
        nayaNode->prev=fakeHead;

        nayaNode->next=temp;
        temp->prev=nayaNode;
    }
    

    void push_back(int x)
    {
        Node* nayaNode=new Node(x);
        Node* temp=fakeTail->prev;

        nayaNode->next=fakeTail;
        fakeTail->prev=nayaNode;

        temp->next=nayaNode;
        nayaNode->prev=temp;
    }

    void pop_front()
    {
        if(fakeHead->next==fakeTail)
        {
            cout<<"underflow"<<endl;
            return ;
        }

        Node* temp=fakeHead->next->next;
        delete(fakeHead->next);

        fakeHead->next=temp;
        temp->prev=fakeHead;
    }   

    void pop_back()
    {
        
        if(fakeHead->next==fakeTail)
        {
            cout<<"underflow"<<endl;
            return ;
        }

        Node* temp=fakeTail->prev->prev;
        delete(fakeTail->prev);
        temp->next=fakeTail;
        fakeTail->prev=temp;
    }

    int front()
    {
        if(fakeHead->next==fakeTail)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return fakeHead->next->data;
    }

    int back()
    {
        if(fakeHead->next==fakeTail)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return fakeTail->prev->data;
    }
};

int main()
{

    Deque dq;
    dq.push_back(10);
    dq.push_back(11);
    dq.push_back(12);
    cout<<dq.back()<<endl;
    cout<<dq.front()<<endl;
    dq.push_front(14);

    cout<<dq.front()<<endl;

    dq.pop_front();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    cout<<dq.back()<<endl;

    return 0;
}