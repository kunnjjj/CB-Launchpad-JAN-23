#include<iostream> 
#include<queue>
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


node* buildTree()
{
    int d; cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* nayaNode=new node(d);
    nayaNode->left=buildTree();
    nayaNode->right=buildTree();
    return nayaNode;
}

void preOrder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)
{
    if(root==NULL) return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root)
{
    if(root==NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


void invertTree(node* root)
{
    if(root==NULL) { return; }

    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
}

void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty()) // TO-DO
    {
        node* frontNode=q.front();
        cout<<frontNode->data<<" ";
        q.pop();
        if(frontNode->left!=NULL) q.push(frontNode->left);
        if(frontNode->right!=NULL) q.push(frontNode->right);
    }

}

void levelWiseJugaad(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int nodesInCurLevel=q.size(); 

        for(int i=1;i<=nodesInCurLevel;i++)
        {
            node* frontNode=q.front();
            cout<<frontNode->data<<" ";
            q.pop();
            if(frontNode->left!=NULL) q.push(frontNode->left);
            if(frontNode->right!=NULL) q.push(frontNode->right);
        }
        cout<<endl;
    }
    cout<<endl;
}

void levelWiseUsingDelimiter(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL); 
    // NULL is delimiter that is pushed when a level gets completed
    while ((int)q.size()>1)
    {
        node* frontNode=q.front();
        q.pop();

        if(frontNode==NULL)
        {
            // prev level has been completed 
            // and next level is pushed
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<frontNode->data<<" ";
        if(frontNode->left!=NULL) q.push(frontNode->left);
        if(frontNode->right!=NULL) q.push(frontNode->right);
    }
    
}

int height(node* root)
{

}


int main()
{
    node* root=buildTree();

    inOrder(root);
    cout<<endl;

    preOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;


    return 0;
}