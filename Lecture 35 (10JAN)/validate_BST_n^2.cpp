// https://leetcode.com/problems/validate-binary-search-tree/description/
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

    long long inf=(long long)1e13;
    long long maxInSubtree(TreeNode* root)
    {
        if(root==NULL) return -inf;
        TreeNode* temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp->val;
    } 

    long long minInSubtree(TreeNode* root)
    {
        if(root==NULL) return +inf;
        TreeNode* temp=root;
        while(temp->left!=NULL) temp=temp->left;
        return temp->val;
    }


    bool isValidBST(TreeNode* root) {
        // returns true if subtree of root is a BST
        if(root==NULL)
        {
            return true;
        }

        if(maxInSubtree(root->left) < root->val &&
            root->val < minInSubtree(root->right) &&
            isValidBST(root->left) &&
            isValidBST(root->right)){
                return true;
        }
        return false;
    }
};