/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL)
       {
           return NULL;
       } 
        // case1: q lies inside subtree of p
        // case2: p lies inside subtree of q
        // case3: they both do not lie inside each other's subtree
       if(root==p) return p; // case1, case3
       if(root==q) return q; // case2, case3
       TreeNode* leftMeinMila=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightMeinMila=lowestCommonAncestor(root->right,p,q);
        if(leftMeinMila!=NULL && rightMeinMila!=NULL)
        {
            return root;
        }
        if(leftMeinMila!=NULL && rightMeinMila==NULL)
        {
            return leftMeinMila;
        }
        if(leftMeinMila==NULL && rightMeinMila!=NULL)
        {
            return rightMeinMila;
        }
        return NULL;
    }
};

// WE WANT 'ULTA TREE', for every node we must have a pointer to its parent