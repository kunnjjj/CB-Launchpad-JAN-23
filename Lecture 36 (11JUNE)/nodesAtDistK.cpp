// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void nodesAtDistKInSubtree(TreeNode* root,int k)
    {
        if(root==NULL || k<0)
        {
            return ;
        }
        if(k==0)
        {
            // cout<<root->data<<" ";
            ans.push_back(root->val);
            return ;
        }
        nodesAtDistKInSubtree(root->left,k-1);
        nodesAtDistKInSubtree(root->right,k-1);
    }
    
    int distFromTarget(TreeNode* root,TreeNode* target,int k)
    {
        // -1 means that target node is not found
        // any non negative value means that target was found
        if(root==NULL)
        {
            return -1; 
        }

        if(root==target)
        {
            nodesAtDistKInSubtree(root,k);
            return 0;
        }
        int dLeft=distFromTarget(root->left,target,k);
        
        if(dLeft!=-1)
        {
            // target node mili
            int dRoot=1 + dLeft;
            if(dRoot==k)
            {
                ans.push_back(root->val);
            }
            nodesAtDistKInSubtree(root->right,k-dRoot-1);
            return dRoot;
        }

        int dRight=distFromTarget(root->right,target,k);

        if(dRight!=-1)
        {
            // target node mila
            int dRoot=1 + dRight;
            if(dRoot==k)
            {
                ans.push_back(root->val);
            }
            nodesAtDistKInSubtree(root->left,k-dRoot-1);
            return dRoot;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        distFromTarget(root,target,k);
        return ans;
    }
};