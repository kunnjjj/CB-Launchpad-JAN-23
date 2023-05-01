#include<iostream>
#include<vector>
using namespace std;

bool solve()
{
	int N; cin>>N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin>>A[i];

	for(int i=0;i<N;i++) if(A[i]==0) return true;

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(A[i]+A[j]==0) return true;
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			for(int k=j+1;k<N;k++)
				if(A[i]+A[j]+A[k]==0) return true;
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			for(int k=j+1;k<N;k++)
				for(int l=k+1;l<N;l++)
				if(A[i]+A[j]+A[k]+A[l]==0) return true;
		}
	}
	return false;

}

int main() {
	int t; cin>>t;
	while(t--)
	{
		if(solve())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
