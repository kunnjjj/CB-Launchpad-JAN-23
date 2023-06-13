// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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
    void flatten(TreeNode* root) {

        while(root!=NULL) // TODO
        {
            TreeNode* temp=root->right;
            TreeNode* leftTraversal=root->left;
            if(leftTraversal==NULL)
            {
                root=root->right;
            }
            else
            {
                while(leftTraversal->right!=NULL)
                {
                    leftTraversal=leftTraversal->right;
                }
                leftTraversal->right=temp;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
        }
    }
};