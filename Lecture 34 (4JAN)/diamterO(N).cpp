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
    int height(TreeNode* root,int &ans)
    {
        // calculates height of left subtree and also maximises ans variable
        if(root==NULL) return 0;
        int leftHeight=height(root->left,ans);
        int rightHeight=height(root->right,ans);

        int maxLenUsingRoot=leftHeight + rightHeight;
        if(maxLenUsingRoot > ans) ans=maxLenUsingRoot;

        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // returns diameter of subtree of root
        int ans=0;
        height(root,ans);
        return ans;
    }
};
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

    pair<int,int> helper(TreeNode* root)
    {
        // returns a pair, the first element denotes the diameter, 
        // second element denotes the height
        if(root==NULL)
        {
            pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }

        pair<int,int> leftPair=helper(root->left);
        pair<int,int> rightPair=helper(root->right);

        int myHeight=1 + max(leftPair.second,rightPair.second);
        int myDiamater=max({
            leftPair.first,
            rightPair.first,
            leftPair.second + rightPair.second
        });

        pair<int,int> p;
        p.first=myDiamater;
        p.second=myHeight;
        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // returns diameter of subtree of root
        
        return helper(root).first;
    }
};/**
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

    pair<int,int> helper(TreeNode* root)
    {
        // returns a pair, the first element denotes the diameter, 
        // second element denotes the height
        if(root==NULL)
        {
            pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }

        pair<int,int> leftPair=helper(root->left);
        pair<int,int> rightPair=helper(root->right);

        int myHeight=1 + max(leftPair.second,rightPair.second);
        int myDiamater=max({
            leftPair.first,
            rightPair.first,
            leftPair.second + rightPair.second
        });

        pair<int,int> p;
        p.first=myDiamater;
        p.second=myHeight;
        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // returns diameter of subtree of root
        
        return helper(root).first;
    }
};