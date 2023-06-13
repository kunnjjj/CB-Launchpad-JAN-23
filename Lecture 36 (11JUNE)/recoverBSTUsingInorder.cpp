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
    
    vector<TreeNode*> inorder; 

    void traverse(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        traverse(root->left);
        inorder.push_back(root);
        traverse(root->right);
    }

    void recoverTree(TreeNode* root) {
        pair<TreeNode*,TreeNode*> dikkat={NULL,NULL};
        traverse(root); // inorder ko bhardia hoga

        int n=inorder.size();
        for(int i=0;i<=n-2;i++)
        {
            if(inorder[i]->val > inorder[i+1]->val)
            {
                if(dikkat.first==NULL)
                {
                    dikkat.first=inorder[i];
                    dikkat.second=inorder[i+1];
                }
                else
                {
                    dikkat.second=inorder[i+1];
                }
            }
        }

        swap(dikkat.first->val,dikkat.second->val);
    }   
};