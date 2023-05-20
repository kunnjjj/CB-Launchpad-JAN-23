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
    bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
            if(fast==slow)
            {
                
                return true;
                // CYCLE FOUND
                // INORDER TO REMOVER CYCLE 
                
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    prev=slow;
                    slow=slow->next;
                }
                prev->next=NULL;
            }
        }
        return false;
    }
};