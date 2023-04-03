#include<iostream>
#include<climits>
using namespace std;


void solve()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int kadane_ans=INT_MIN;
    
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur=max(cur + A[i],A[i]);
        if(cur >  kadane_ans) kadane_ans=cur;
    }

    if(kadane_ans < 0) 
    {
        cout<<kadane_ans<<endl;
        return ;
    }
    int worst=0,most_kharab=INT_MAX;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        worst=min(worst + A[i],A[i]);
        if(worst < most_kharab)
        {
            most_kharab=worst;
        }
    }
    cout<<max(kadane_ans,sum-most_kharab)<<endl;
}

int main()
{

    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}