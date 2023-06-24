// https://hack.codingblocks.com/app/contests/1236/1353/problem
#include<iostream>
using namespace std;
int A[2001];
int B[2001];

int dp[2001][2001][5];
int n,m; 
int func(int i,int j,int k)
{

	if(i==n || j==m) return 0;

	if(dp[i][j][k]!=-1)
	{
		return dp[i][j][k];
	}

	if(A[i]==B[j])
	{
		return dp[i][j][k]=1 + func(i+1,j+1,k);
	}
	else
	{
		int op1=0,op2=0,op3=0;
		if(k>0)
		{
			op1=1 + func(i+1,j+1,k-1);
		}
		op2=func(i+1,j,k);
		op3=func(i,j+1,k);
		return dp[i][j][k]=max(max(op1,op2),op3);
	}
}
int main() {
	cin>>n>>m;
	int k; cin>>k;
	for(int i=0;i<n;i++) cin>>A[i];
	for(int j=0;j<m;j++) cin>>B[j];

	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	for(int x=0;x<=k;x++) dp[i][j][x]=0;

	// cout<<func(0,0,k)<<endl;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			for(int x=0;x<=k;x++)
			{
				// dp[i][j][x]
				// max length of lcs in 
				// A[i...n-1], B[j...m-1]
				// with x operattions remaining
				if(A[i]==B[j])
				{
					dp[i][j][x]=1 + dp[i+1][j+1][x];
				}
				else
				{
					int op1=0,op2=0,op3=0;
					if(x>0)
					{
						op1=1+ dp[i+1][j+1][x-1];
					}
					op2=dp[i+1][j][x];
					op3=dp[i][j+1][x];
					dp[i][j][x]=max(max(op1,op2),op3);
				}
				
			}
		}
	}

	cout<<dp[0][0][k]<<endl;

	return 0;
}
