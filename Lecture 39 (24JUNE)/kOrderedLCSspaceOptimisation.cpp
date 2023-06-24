// https://hack.codingblocks.com/app/contests/1236/1353/problem
#include<bits/stdc++.h>

using namespace std;
#define deb(x) cout<<(#x)<<": "<<x<<endl
int main() {
    int n,m; 
	cin>>n>>m;
	int k; cin>>k;
    vector<int> A(n);
    vector<int> B(m);

	for(int i=0;i<n;i++) cin>>A[i];
	for(int j=0;j<m;j++) cin>>B[j];

    vector<vector<int>> dpOld(m+1,vector<int> (k+1));
    // cout<<"runn"<<endl;
	for(int i=n-1;i>=0;i--)
	{
        vector<vector<int>> dpNow(m+1,vector<int> (k+1));
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
					// dp[i][j][x]=1 + dp[i+1][j+1][x];
                    dpNow[j][x]=1 + dpOld[j+1][x];
				}
				else
				{
					int op1=0,op2=0,op3=0;
					if(x>0)
					{
						// op1=1+ dp[i+1][j+1][x-1];
                        op1=1 + dpOld[j+1][x-1];
					}
					// op2=dp[i+1][j][x];
                    op2=dpOld[j][x];
					// op3=dp[i][j+1][x];
                    op3=dpNow[j+1][x];
                    dpNow[j][x]=max(max(op1,op2),op3);
					// dp[i][j][x]=max(max(op1,op2),op3);
				}
                // deb(i);
                // deb(j);
                // deb(x);
                // deb(dpNow[j][x]);
                
            }

		}
        
        dpOld=dpNow;
	}

	cout<<dpOld[0][k]<<endl;



	return 0;
}