// https://hack.codingblocks.com/app/contests/1236/1255/problem
#include<bits/stdc++.h>
using namespace std;
int main() {

	int n; cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	
    // P1: VARUN
    // P2: KUNJ
    vector<vector<int>> dp(n,vector<int> (n));
    
	for(int L=n-1;L>=0;L--)
	{
		for(int R=L;R<n;R++)
		{
			// dp[L][R]
			// max score p1 gets from subarray A[L]...A[R]
            // if both play optimally
            
            // A[L,L+1,L+2,L+3......,R-2,R-1,R]

            //CASE VARUN CHOOSES A[L]

            int scoreKunjChoosesForVarunIfHetakeA_L=
            min(
                // func(L+2,R)
                (L+2<=R?dp[L+2][R]:0), // if K chose A[L+1], varun get  
                (L+1<=R-1?dp[L+1][R-1]:0) // if K chose A[R], varun gets
            );

            int option1ForVarun=A[L] + scoreKunjChoosesForVarunIfHetakeA_L;

            int scoreKunjChoosesForVarunIfHetakeA_R=
            min(
                (L+1<=R-1?dp[L+1][R-1]:0), // if K chose A[L]
                (L<=R-2?dp[L][R-2]:0) // if K chose A[R-1];
            );

            int option2ForVarun=A[R] + scoreKunjChoosesForVarunIfHetakeA_R;

            // dp[L][R] max score V gets from A[L...R] if both play optimally

            dp[L][R]=max(option1ForVarun,option2ForVarun);
		}
	}

    cout<<dp[0][n-1]<<endl;

	return 0;
}