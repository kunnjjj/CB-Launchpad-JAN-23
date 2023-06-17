#include<bits/stdc++.h> 
using namespace std; 



int fib(int n,vector<int> &dp)
{
    if(n==0 or n==1) return n;

    // if(dp[n]==-1) is fib(n) ka ans nahi nikla

    if(dp[n]!=-1)  return dp[n];

    dp[n]=fib(n-1,dp) + fib(n-2,dp);
   return dp[n];
}

int main()
{

    int n; cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp)<<endl;

    vector<int> FIB(n+1);

    FIB[0]=0;
    FIB[1]=1;

    for(int i=2;i<=n;i++)
    {
        FIB[i]=FIB[i-1] + FIB[i-2];
    }

    cout<<FIB[n]<<endl;




    return 0;
}