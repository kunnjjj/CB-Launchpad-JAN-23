#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

void buildTree(node*& root,int d)
{
    if(root==NULL)
    {
        node* nayaNode=new node(d);
        root=nayaNode;
        return ;
    }
    if(d <= root->data)
    {
        buildTree(root->left,d);
    }
    else
    {
        buildTree(root->right,d);
    }
}

node* inorderSuccessor(node* root) 
{
    // returns inorder successor when right child is present
    node* successor=root->right;
    while(successor->left!=NULL)
    {
        successor=successor->left;
    }
    return successor;
}


node* inorderPredecessor(node* root)
{
    // if left child is present
    node* predecessor=root->left;
    while(predecessor->right!=NULL) 
    {
        predecessor=predecessor->right;
    }
    return predecessor;
}


node* deleteFromBST(node* root,int targetData)
{
    // return updated root
    if(root==NULL) return NULL;

    if(root->data==targetData)
    {
        // CASE WORK
        // Case1: Root is leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        
        // Case2(A): Root only has left child
        if(root->left!=NULL && root->right==NULL)
        {
            node* updatedRoot=root->left;
            delete(root);
            return updatedRoot;
        }

        // Case2(B): Root only has right child
        if(root->left==NULL && root->right!=NULL)
        {
            node* updatedRoot=root->right;
            delete(root);
            return updatedRoot;
        }

        node* successor=inorderSuccessor(root);
        swap(root->data,successor->data);
        root->right=deleteFromBST(root->right,targetData);
    }

    if(targetData < root->data)
    {
        root->left=deleteFromBST(root->left,targetData);
    }
    else
    {
        root->right=deleteFromBST(root->right,targetData);
    }
    return root;
}

void preorder(node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void solve()
{
    int n; cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        int d; cin>>d;
        buildTree(root,d);
    }

    int m; cin>>m;
    for(int i=0;i<m;i++)
    {
        int target; cin>>target;
        root=deleteFromBST(root,target);
    }

    preorder(root);
    cout<<endl;

}

int main() {

    int t; cin>>t;
    while(t--) solve();
	return 0;
}