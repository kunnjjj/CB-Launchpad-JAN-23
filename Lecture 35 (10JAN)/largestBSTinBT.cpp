#include <bits/stdc++.h>
//#include <queue>
using namespace std;


class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

class Quadruplet{
public:
    long long maxInSubtree;
    long long minInSubtree;
    bool isBST;
    long long inf=1e13;
    int sizeOfSubtree;
    Quadruplet()
    {
        maxInSubtree=-inf;
        minInSubtree=+inf;
        sizeOfSubtree=0;
        isBST=true;
    }
};


int idx=0;
node* createPreorderInorder(int* preorder,int* inorder,int start,int end)
{
    if(start>end)
        return NULL;
    node* root=new node(preorder[idx]);
    int i=-1;
    for(i=start;i<=end;i++)
        if(inorder[i]==preorder[idx])
        break;
        idx++;
    root->left= createPreorderInorder(preorder,inorder,start,i-1);

    root->right=createPreorderInorder(preorder,inorder,i+1,end);
    return root;
}
int ans=0;
Quadruplet helper(node* root)
{	
	Quadruplet q;
	if(root==NULL) return q;

	Quadruplet leftRes=helper(root->left);
	Quadruplet rightRes=helper(root->right);

	q.maxInSubtree=max({
						leftRes.maxInSubtree,
						rightRes.maxInSubtree,
						(long long)root->data
                    });
	q.minInSubtree=min({
					leftRes.minInSubtree,
					rightRes.minInSubtree,
					(long long)root->data
				});
	q.isBST= leftRes.isBST && rightRes.isBST &&
		leftRes.maxInSubtree < root->data &&
		root->data < rightRes.minInSubtree;
	q.sizeOfSubtree=1 + leftRes.sizeOfSubtree + rightRes.sizeOfSubtree;
	if(q.isBST)
	{
		ans=max(ans,q.sizeOfSubtree);
	}
	return q;
}
int main()
{
    node* root;
    int n;
    cin>>n;

    int *preorder=new int[n];
    for(int i=0;i<n;i++)
        cin>>preorder[i];
    int *inorder=new int[n];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    root=createPreorderInorder(preorder,inorder,0,n-1);

	helper(root);

	cout<<ans<<endl;

   	
    return 0;
}