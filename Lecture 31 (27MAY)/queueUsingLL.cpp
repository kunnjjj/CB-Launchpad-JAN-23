#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};


class Queue
{

    Node* head;
    Node* tail;
    public:

    Queue()
    {
        tail=NULL;
        head=NULL;
    }

    void insertAtTail(int x)
    {
        if(tail==NULL)
        {
            // Node* nayaNode=new Node(x);
            tail=new Node(x);
            // tail=nayaNode;
            head=tail;
            return ;
        }

        tail->next=new Node(x);
        tail=tail->next;
    }

    void deleteAtHead()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            return ;
        }
        Node* temp=head->next;
        delete(head);
        head=temp;
    }

    void push(int x)
    {
        insertAtTail(x);
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            return ;
        }
        deleteAtHead();
    }

    int front()
    {
        if(head==NULL)
        {
            cout<<"underflow"<<endl;
            return -1;
        }

        return head->data;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(4);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}