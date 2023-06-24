// https://hack.codingblocks.com/app/contests/1236/35/problem
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
	string P,Q,R;
	cin>>P>>Q>>R;
	int a,b,c; 
	a=P.size();
	b=Q.size();
	c=R.size();
	// int dp[201][201][201];
	vector<vector<vi>> dp(a,vector<vi> (b,vi(c,0)));
	// cout<<"HI"<<endl;
	// memset(dp,0,sizeof(dp));
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			for(int k=0;k<c;k++)
			{
				if(P[i]==Q[j] && Q[j]==R[k])
				{
					dp[i][j][k]=1+(i-1>=0 && j-1>=0 && k-1>=0?dp[i-1][j-1][k-1]:0);

				}
				else
				{
					dp[i][j][k]=max({(i-1>=0?dp[i-1][j][k]:0),(j-1>=0?dp[i][j-1][k]:0),(k-1>=0?dp[i][j][k-1]:0)});
				}
			}
		}
	}
	cout<<dp[a-1][b-1][c-1]<<endl;
	return 0;
}