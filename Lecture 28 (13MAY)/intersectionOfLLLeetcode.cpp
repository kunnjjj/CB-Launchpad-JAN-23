/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lenOfLL(ListNode* head)
    {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=lenOfLL(headA);
        int lenB=lenOfLL(headB);

        // convention: headA is LL with longer length
        if( lenA < lenB)
        {
            swap(headA,headB);
            swap(lenA,lenB);
        }

        for(int i=1;i<=lenA-lenB;i++)
        {
            headA=headA->next;
        }
        

        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL && tempB!=NULL)
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        if(tempA==NULL)
        {
            while(tempB!=NULL)
            {
                tempB=tempB->next;
                headB=headB->next;
            }
        }
        else
        {
            
            while(tempA!=NULL)
            {
                tempA=tempA->next;
                headA=headA->next;
            }
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};