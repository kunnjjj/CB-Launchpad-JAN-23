#include<bits/stdc++.h> 
using namespace std; 

int minCost(int i,int n,vector<int> &stones,vector<int> &dp)
{
    // assuming stones array[1...n]
    // returns minCost to reach from ith index to nth index
    if(i==n)
    {
        return 0;
    }

    if(dp[i]!=-1)
    {
        return dp[i];
    }


    int inf=1e9;
    int op1=inf,op2=inf;

    op1= abs(stones[i]-stones[i+1]) + minCost(i+1,n,stones,dp);

    if(i+2<=n)
    {
        op2=abs(stones[i]-stones[i+2]) + minCost(i+2,n,stones,dp);
    }   

    return dp[i]=min(op1,op2);
}



int main()
{
    int n; cin>>n;
    vector<int> stones(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>stones[i];
    }

    vector<int> dp(n+1,-1);
    cout<<minCost(1,n,stones,dp)<<endl;
    return 0;
}