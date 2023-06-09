#include<bits/stdc++.h>
using namespace std;

class node{
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

int idx=0;
// idx can be passed in func by ref also

node* buildTreeUsingInorderPreorder(vector<int> &inorder,vector<int> &preorder,int s,int e)
{
	if(s > e)
	{
		return NULL;
	}
	int rootKaData=preorder[idx];
	idx++;
	node* root=new node(rootKaData);

	int foundAt=-1;
	for(int i=s;i<=e;i++)
	{
		if(inorder[i]==rootKaData)
		{
			foundAt=i;
			break;
		}
	}
	root->left=buildTreeUsingInorderPreorder(inorder,preorder,s,foundAt-1);
	root->right=buildTreeUsingInorderPreorder(inorder,preorder,foundAt+1,e);
	return root;
}

void Preorder(node* root)
{
	if(root==NULL) return ;

	if(root->left!=NULL)
	{
		cout<<root->left->data<<" ";
	}
	else
	{
		cout<<"END ";
	}
	cout<<"=> ";

	cout<<root->data<<" ";

	cout<<"<= ";
	if(root->right!=NULL)
	{
		cout<<root->right->data<<endl;
	}
	else
	{
		cout<<"END"<<endl;
	}
	
	Preorder(root->left);
	Preorder(root->right);
}

int main() {

	int N; cin>>N;
	vector<int> preorder(N);
	for(int i=0;i<N;i++) cin>>preorder[i];


	cin>>N;
	vector<int> inorder(N);
	for(int i=0;i<N;i++) cin>>inorder[i];

	node* root=buildTreeUsingInorderPreorder(inorder,preorder,0,N-1);

	Preorder(root);
	return 0;
}