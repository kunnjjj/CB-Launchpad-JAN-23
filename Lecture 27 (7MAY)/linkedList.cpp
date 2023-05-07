#include<iostream> 
using namespace std; 

class node
{
    public:
    int data;
    node* next;
    node(int D)
    {
        data=D;
        next=NULL;
    }
};

void insertAtTail(node*& head,node*& tail,int d)
{
    if(head==NULL)
    {
        node* nayiNode=new node(d);
        head=nayiNode;
        tail=nayiNode;
        return ;
    }

    node* nayiNode=new node(d);
    // (*tail).next=nayiNode;
    tail->next=nayiNode;
    tail=nayiNode;
}

void insertAtHead(node*& head,node*& tail,int d)
{

}


int main()
{
    node* head=NULL;
    node* tail=NULL;

    insertAtTail(head,tail,3);

    insertAtTail(head,tail,5);





    return 0;
}