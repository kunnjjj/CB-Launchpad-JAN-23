#include<iostream>
#include<algorithm>
using namespace std;

bool comp(string &a,string &b)
{
	string op1=a+b;
	string op2=b+a;
	if(op1 > op2)
	{
		return true;
	}
	else return false;
}

int main() {
	int t; cin>>t;
	while(t--)
    {
		int n; cin>>n;
		string A[n];
		for(int i=0;i<n;i++) cin>>A[i];

		sort(A,A+n,comp);
		for(int i=0;i<n;i++) cout<<A[i];
		cout<<endl;
	}
	return 0;
}