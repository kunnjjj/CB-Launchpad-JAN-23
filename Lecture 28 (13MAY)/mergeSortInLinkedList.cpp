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


node *middleUsingFastSlow(node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    node *slow = head;
    node *fast = slow->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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


node* mergeSort(node* headA)
{
    if(headA==NULL or headA->next==NULL)
    {
        return headA;
    }

    node* middleNode=middleUsingFastSlow(headA);
    node* headB=middleNode->next;
    middleNode->next=NULL; 
    headA=mergeSort(headA); // left side
    headB=mergeSort(headB); // right side
    return mergeSortedLL(headA,headB);
}
int main()
{
    node* headA=NULL,*tailA=NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insertAtTail(headA, tailA, d);
    }


    print(headA);
    // cout<<"yo whatsupp"<<endl;

    node* sortedHead=mergeSort(headA);

    print(sortedHead);


    return 0;
}