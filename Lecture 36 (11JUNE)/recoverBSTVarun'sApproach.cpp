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
    vector<int> inorder; 
    int idx;
   

    void traverse(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

    void traverse2(TreeNode* root)
    {
        if(root==NULL) return ;
        traverse2(root->left);
        root->val=inorder[idx];
        idx++;
        traverse2(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root); // inorder ko bhardia hoga
        sort(inorder.begin(),inorder.end());

        idx=0;
        traverse2(root);
    }   
};