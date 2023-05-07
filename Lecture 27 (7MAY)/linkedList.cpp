#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int D)
    {
        data = D;
        next = NULL;
    }

    ~node()
    {
        cout<<"destructor called"<<endl;
    }
};

void insertAtTail(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *nayiNode = new node(d);
        head = nayiNode;
        tail = nayiNode;
        return;
    }

    node *nayiNode = new node(d);
    // (*tail).next=nayiNode;
    tail->next = nayiNode;
    tail = nayiNode;
}

void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *nayiNode = new node(d);
        head = nayiNode;
        tail = nayiNode;
        return;
    }

    node *nayiNode = new node(d);
    // (*nayiNode).next=head;
    nayiNode->next=head;
    head = nayiNode;
}

void printLL(node *head)
{
    // node *temp = head;

    // // cout<<(*temp).data<<" ---> ";
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ---> ";
    //     temp = temp->next;
    // }

    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<endl;

}

void printRec(node* head)
{
    if(head==NULL)
    {
        cout<<endl;
        return ;
    }
    cout<<head->data<<" ---> ";
    printRec(head->next);
}



void func(node*& EXPLAIN)
{
    cout<<"address of Explain inside func: "<<(&EXPLAIN)<<endl;
    cout<<EXPLAIN<<endl;
}

int lenOfLL(node *head)
{
    // node *temp = head;

    // // cout<<(*temp).data<<" ---> ";
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ---> ";
    //     temp = temp->next;
    // }
    int len=0;
    while(head!=NULL)
    {
        // cout<<head->data<<" ---> ";
        len++;
        head=head->next;
    }
    return len;
}

int lenRec(node* head)
{
    if(head==NULL) return 0;
    return 1 + lenRec(head->next);
}


ostream& operator<<(ostream& o,node* head)
{
    printLL(head);
    return o;
}

void deleteLL(node*& head)
{
    if(head==NULL) return ;
    deleteLL(head->next);
    delete(head);
    head=NULL;
}

void insertAtPos(node*& head,node*& tail,int d,int pos)
{
    if(pos==1 or head==NULL)
    {
        insertAtHead(head,tail,d);
        return ;
    }
    if(pos > lenOfLL(head))
    {
        insertAtTail(head,tail,d);
        return ;
    }
    node* temp=head;
    for(int i=1;i<=pos-2;i++)
    {
        temp=temp->next;
    }
    node* nayiNode=new node(d);
    nayiNode->next=temp->next;
    temp->next=nayiNode;
}

int main()
{
    // node *head = NULL;
    // node *tail = NULL;

    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);
    // insertAtTail(head, tail, 7);

    // insertAtHead(head,tail,3);

    // printLL(head);
    // printLL(head);



    // node* EXPLAIN=new node(12);
    // cout<<EXPLAIN<<endl;
    // cout<<"address of Explain: "<<(&EXPLAIN)<<endl;
    // func(EXPLAIN);


    cout<<"--------------------------"<<endl;
    node* head=NULL;
    node* tail=NULL;

    int d; 
    cin>>d;

    while(d!=-1)
    {
        insertAtTail(head,tail,d);
        cin>>d;
    }

    // printLL(head);
    // cout<<lenOfLL(head)<<endl;
    
    printRec(head);
    cout<<lenRec(head)<<endl;

    node* head1=NULL;
    node* tail1=NULL;

    cin>>d;
    while(d!=-1)
    {
        insertAtTail(head1,tail1,d);
        cin>>d;
    }


    printLL(head1);
    cout<<lenOfLL(head1)<<endl;

    cout<<"-----------USING OPERATOR OVERLOADING--------"<<endl;


    // cout<<head;
    // cout<<endl;

    // cout<<head1;

    cout<<head<<head1<<endl;

    cout<<"deleting LL 1"<<endl;
    deleteLL(head);

    cout<<"deleting LL 2"<<endl;
    deleteLL(head1);

    cout<<"printing LL1: "<<head<<endl;
    cout<<"printing LL2: "<<head1<<endl;

    int pos; cin>>pos; 
    int d; cin>>d;
    insertAtPos(head,tail,d,pos);

    cout<<head<<endl;
    

    return 0;
}