#include <iostream>
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

void reverseLinkedList(node *&head, node *&tail)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *prev = NULL, *cur = head;
    while (cur != NULL)
    {
        node *agla = cur->next;
        cur->next = prev;
        prev = cur;
        cur = agla;
    }
    tail = head;
    head = prev;
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

int length(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}

node *middleUsingLen(node *head)
{
    // if(head==NULL)
    // {
    //     return NULL;
    // }
    // if(head->next==NULL)
    // {
    //     return head;
    // }
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = length(head);

    node *temp = head;
    for (int i = 1; i <= (len - 1) / 2; i++)
    {
        temp = temp->next;
    }
    return temp;
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

    // while(true)
    // {
    //     if(fast==NULL or fast->next==NULL) break;
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    // return slow;

    // bool x=true;
    // cout<<(!x)<<endl;

    // while(!(fast->next==NULL or fast->next==NULL))
    // {
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    // return slow;
}

int main()
{
    node *head = NULL, *tail = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insertAtTail(head, tail, d);
    }

    print(head);

    // reverseLinkedList(head,tail);

    print(head);

    node *middle = middleUsingLen(head);
    cout << "data of middle node " << middle->data << "\n";

    return 0;
}
