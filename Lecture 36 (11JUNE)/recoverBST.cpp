/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* prev;
    TreeNode* cur;
    pair<TreeNode*,TreeNode*> dikkat;

    void traverse(TreeNode* root)
    {
        if(root==NULL) return ;

        traverse(root->left); // prev ko update karke layegi
        
        // DO WORK FOR ROOT
        cur=root;

        if(prev!=NULL && prev->val > cur->val)
        {
            // HANDLE DIKKAT CASE
            if(dikkat.first==NULL)
            {
                dikkat.first=prev;
                dikkat.second=cur;
            }
            else
            {
                dikkat.second=cur;
            }
        }

        prev=cur;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=NULL,cur=NULL;
        dikkat={NULL,NULL};
        traverse(root);
        swap(dikkat.first->val,dikkat.second->val);
    }   
};