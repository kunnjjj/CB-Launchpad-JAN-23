#include<iostream>
using namespace std;

int main() {
	int k; cin>>k;
	string s; cin>>s;

	int i=0;
	int cntA=0,cntB=0;
	int ans=0;
	for(int j=0;j<(int)s.size();j++)
	{
		if(s[j]=='a') cntA++;
		else cntB++;
		while(min(cntA,cntB)>k)
		{
			if(s[i]=='a') cntA--;
			else cntB--;

			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}