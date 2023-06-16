#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node* left;
	node * right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
class trie
{

	public:
	node *root;
	trie()
	{
		root=new node('\0');
	}

	void insertInTrie(int d)
	{
		node *temp=root;
		for(int i=30;i>=0;i--)
		{
			if(d & (1<<i)) // ith bit is 1
			{
				if(temp->right==NULL)
				{
					temp->right=new node(1);
				}
				temp=temp->right;
			}
			else
			{
				if(temp->left==NULL)
				{
					temp->left=new node(0);
				}
				temp=temp->left;
			}
		}
	}
	int maxXorPair(int num)
	{
		int ans=0;
		node *temp=root;
		for(int i=30;i>=0;i--)
		{
			if(num & (1<<i)) // if current bit is 1
			{
				// try moving to the left
				if(temp->left!=NULL)
				{
					temp=temp->left;
					ans+=1<<i;
				}
				else // if we fail to find bit 0, then consider bit 1
				{
					temp=temp->right;
				}
			}
			else // cur bit is 0
			{
				if(temp->right!=NULL)
				{
					temp=temp->right;
					ans+=(1<<i);
				}
				else
				{
					temp=temp->left;
				}
			}
		}
		return ans;
	}

};
int main() {
	int n; cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	vector<int> prefixXor(n);
	prefixXor[0]=A[0];
	for(int i=1;i<n;i++)
	{
		prefixXor[i]=prefixXor[i-1] ^ A[i];
	}
	trie t;
	t.insertInTrie(0);
	for(int i=0;i<n;i++)
	{
		t.insertInTrie(prefixXor[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,t.maxXorPair(prefixXor[i]));// find maxxor value i can get with ith element
	}
	cout<<ans<<endl;
	return 0;
}