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
// Time: O(N)
// Space: O(H)
class Pair
{
    public:
    int height;
    bool isBalanced;
    Pair()
    {
        height=0;
        isBalanced=true;
    }
};

class Solution {
public:
    Pair helper(TreeNode* root)
    {
        Pair P;
        if(root==NULL) return P;

        Pair leftRes=helper(root->left);
        Pair rightRes=helper(root->right);

        P.height=1 + max(leftRes.height,rightRes.height);
        P.isBalanced=leftRes.isBalanced && 
                     rightRes.isBalanced && 
                     (abs(leftRes.height-rightRes.height)<=1);
        return P;            
    }
    bool isBalanced(TreeNode* root) {
        return helper(root).isBalanced;
    }
};