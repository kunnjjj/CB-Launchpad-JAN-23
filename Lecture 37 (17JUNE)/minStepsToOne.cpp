#include<bits/stdc++.h> 
using namespace std; 


int minSteps(int n,vector<int> &dp)
{
    // returns minSteps to go from n to 1
    if(n==1)
    {
        return 0;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int inf=1e9;
    int op1=inf,op2=inf,op3=inf;

    op1 = 1 + minSteps(n-1,dp);

    if(n%2==0)
    {
        op2= 1 + minSteps(n/2,dp);
    }

    if(n%3==0)
    {
        op3=1 + minSteps(n/3,dp);
    }

    dp[n]=min({op1,op2,op3});
    return dp[n];
}

int main()
{

    int n; cin>>n;
    vector<int> dp(n+1,-1);
    cout<<minSteps(n,dp)<<endl;

    int inf=1e9;
    vector<int> MIN_STEPS(n+1);
    MIN_STEPS[1]=0;
    for(int i=2;i<=n;i++)
    {
        int op1=inf,op2=inf,op3=inf;
        op1=1 + MIN_STEPS[i-1];

        if(i%2==0)
        {
            op2=1 + MIN_STEPS[i/2];
        }

        if(i%3==0)
        {
            op3=1 + MIN_STEPS[i/3];
        }

        MIN_STEPS[i]=min({op1,op2,op3});
    }

    cout<<MIN_STEPS[n]<<endl;

    return 0;
}