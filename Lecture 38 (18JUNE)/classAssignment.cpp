// https://hack.codingblocks.com/app/contests/1236/1282/problem

#include<iostream> 
#include<vector>
using namespace std; 


void func(string &op,int reqSize)
{
    if((int)op.size()==reqSize)
    {
        cout<<op<<endl;
        return ;
    }
    int n=op.size();
    if(n==0 or op[n-1]=='a')
    {   
        // include a
        op+='a';
        func(op,reqSize);
        op.pop_back();


        op+='b';
        func(op,reqSize);
        op.pop_back();
    }
    else
    {
        op+='a';
        func(op,reqSize);
        op.pop_back();
    }
}


int cnt(int n,int last_char,vector<vector<int>> &dp)
{
    if(n==1)
    {
        // 
        return 1;
    }

    if(dp[n][last_char]!=-1)
    {
        return dp[n][last_char];
    }


    // returns total strings of length n, that end in last char
    // last_char=0, 'a'
    // last_char=1 'b'

    if(last_char==0)
    {
        return dp[n][last_char]=cnt(n-1,0,dp) + cnt(n-1,1,dp);
    }
    else
    {
        return dp[n][last_char]=cnt(n-1,0,dp);
    }
}

int main()
{
    // int reqSize;
    // cin>>reqSize;

    // string op;
    // func(op,reqSize);


    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
		cout<<"#"<<i<<" : ";
        int n; cin>>n;
        vector<vector<int>> dp(n+1,vector<int> (2,-1));

        cout<<(cnt(n,0,dp) + cnt(n,1,dp))<<endl;
    }

    return 0;
}