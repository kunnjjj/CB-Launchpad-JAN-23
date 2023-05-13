#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *nayaNode = new node(d);
        head = nayaNode;
        tail = nayaNode;
        return;
    }
    node *nayaNode = new node(d);
    tail->next = nayaNode;
    tail = nayaNode;
}

void print(node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }

    cout << head->data << " -> ";
    print(head->next);
}

node* mergeSortedLL(node* headA,node* headB) 
{

    // if(headA==NULL and headB==NULL) return NULL;
    if(headA==NULL)
    {
        return headB;
    }
    if(headB==NULL)
    {
        return headA;
    }
    if(headA->data<=headB->data)
    {
        node* mergedHead=headA;
        mergedHead->next=mergeSortedLL(headA->next,headB);
        return mergedHead;
    }
    else
    {   
        node* mergedHead=headB;
        mergedHead->next=mergeSortedLL(headA,headB->next);
        return mergedHead;
    }
}

int main()
{
    node* headA=NULL,*tailA=NULL;
    node* headB=NULL,*tailB=NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insertAtTail(headA, tailA, d);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        insertAtTail(headB , tailB, d);
    }

    print(headA);
    print(headB);

    node* mergedHead=mergeSortedLL(headA,headB);

    print(mergedHead);

    




    return 0;
}