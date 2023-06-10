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

class Triplet{
public:
    long long maxInSubtree;
    long long minInSubtree;
    bool isBST;
    long long inf=1e13;
    Triplet()
    {
        maxInSubtree=-inf;
        minInSubtree=+inf;
        isBST=true;
    }
};


class Solution {
public:
    Triplet helper(TreeNode* root)
    {
        Triplet T;
        if(root==NULL)
        {
            return T;
        }
        Triplet leftTriplet=helper(root->left);
        Triplet rightTriplet=helper(root->right);

        T.maxInSubtree=max({
                            leftTriplet.maxInSubtree,
                            rightTriplet.maxInSubtree,
                            (long long)root->val
                        });
        T.minInSubtree=min({        
                            leftTriplet.minInSubtree,
                            rightTriplet.minInSubtree,
                            (long long)root->val
                        }); 
        T.isBST= leftTriplet.isBST && rightTriplet.isBST &&
                leftTriplet.maxInSubtree < root->val &&
                root->val < rightTriplet.minInSubtree;
        return T;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root).isBST;
    }
};