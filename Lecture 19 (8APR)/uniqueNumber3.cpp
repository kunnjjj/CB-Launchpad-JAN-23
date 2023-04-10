#include<iostream>
using namespace std;

int main() {
	int n; cin>>n;
	int A[n];

	for(int i=0;i<n;i++) cin>>A[i];

	int freq[31]={0};

	for(int j=0;j<n;j++)
	{
		int cur_num=A[j];
		for(int i=0;i<=30;i++)
		{
			// if ith bit of cur_num is 1 then i will increase freq[i] by 1
			if((cur_num>>i)&1==1)
			{
				freq[i]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=30;i++)
	{
		if(freq[i]%3==1)
		{
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;



	return 0;
}
