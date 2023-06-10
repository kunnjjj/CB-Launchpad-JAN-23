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

bool search(node* root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }

    if(key < root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

void preorder(node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int inf=1e9;

int maxInBst(node* root)
{
    if(root==NULL)
    {
        return -inf;
    }

    node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp->data;
}

int minInBst(node* root)
{
    if(root==NULL)
    {
        return +inf;
    }

    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}


// e,

// a * e = a
// a + 0 = a
// a * 1 = a
// a / 1 = a

// min(a,e)=a, e= inf

// max(a,e)=a , e=-inf

// * represents some opertion


int main()
{
    int d; 
    cin>>d;
    node* root=NULL;
    while(d!=-1)
    {
        buildTree(root,d);
        cin>>d;
    }

    preorder(root);

    int key; cin>>key;

    cout<<search(root,key);

    

    return 0;
}