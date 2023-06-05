// https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // returns diameter of subtree of root
        if(!root) return 0;


        // diameter can be from the following cases
        int diameterOfLeftSubtree=diameterOfBinaryTree(root->left);
        int diameterOfRightSubtree=diameterOfBinaryTree(root->right);

        int maxLenPathIncludingRoot=height(root->left) + height(root->right);
        return max({diameterOfLeftSubtree,diameterOfRightSubtree,maxLenPathIncludingRoot});
        
    }
};