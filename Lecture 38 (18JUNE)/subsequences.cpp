// https://hack.codingblocks.com/app/contests/1236/153/problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void func(string &ip,string &out,int i,vector<string> &ans)
{	
	if(i==(int)ip.size())
	{
		// cout<<out<<endl;
		ans.push_back(out);
		return ;
	}


	func(ip,out,i+1,ans);

	out+=ip[i];
	func(ip,out,i+1,ans);
	out.pop_back();

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string ip; cin>>ip;
		vector<string> ans;
		string op;
		func(ip,op,0,ans);

		sort(ans.begin(),ans.end());
		for(int i=0;i<(int)ans.size();i++)
		{
			cout<<ans[i]<<endl;
		}

	}
	return 0;
}