// https://leetcode.com/problems/balanced-binary-tree/description/
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
// Time: O(n^2)
// Space: O(H)
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if( (abs(leftHeight-rightHeight)<=1) && isBalanced(root->left) && isBalanced(root->right))
        {   
            return true;
        }
        else 
        {
            return false;
        }
    }
};