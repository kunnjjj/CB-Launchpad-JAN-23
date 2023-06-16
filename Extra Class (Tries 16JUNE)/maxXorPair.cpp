// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Node
{
    public:
    int data;
    Node* left; // if cur bit =0 then i move along left child
    Node* right; // if cur bit= 1 then i move along right child
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

class Trie
{
    public:
    Node* root;
    int maxBit;
    Trie(int maxBit)
    {
        root=new Node('\0');
        this->maxBit=maxBit; //???
    }

    void insert(int x)
    {
        Node* temp=root;
        for(int i=maxBit;i>=0;i--)
        {
            int curBit=(x>>i)&1;
            if(curBit)
            {
                if(temp->right==NULL)
                {
                    temp->right=new Node(curBit);
                }
                temp=temp->right;
            }
            else
            {
                if(temp->left==NULL)
                {
                    temp->left=new Node(curBit);
                }
                temp=temp->left;
            }
        }   
    }

    int maxXor(int x)
    {
        Node* temp=root;
        int res=0;
        for(int i=maxBit;i>=0;i--)
        {
            int curBit=(x>>i)&1;
            if(curBit)
            {
                // for max xor I will try to find a bit which is 0
                if(temp->left)
                {
                    temp=temp->left;
                    res+=(1<<i); // pow(2,i)
                }
                else
                {
                    temp=temp->right;
                }
            }
            else
            {
                // for max xor I will try to find a bit which is 1
                if(temp->right)
                {
                    temp=temp->right;
                    res+=(1<<i); // pow(2,i)
                }
                else
                {
                    temp=temp->left;
                }
            }
        }        
        return res;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie(30);

        for(int i=0;i<(int)nums.size();i++)
        {
            trie.insert(nums[i]);
        }
        
        int ans=0;
        for(int i=0;i<(int)nums.size();i++)
        {
            ans=max(ans,trie.maxXor(nums[i]));
        }
        return ans;
    }
};