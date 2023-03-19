#include<iostream>
#include<climits>
// #include<algorithm>
using namespace std;

// HW : O(n^3) and O(n^2) do yourself
int kadane1(int *A,int n)
{
    int best[n];
    int ans=INT_MIN;
    for(int i=0;i<n;i++) 
    {
        best[i]=max(
            (i-1>=0?best[i-1]:0) + A[i], // old subarray mein continue
            A[i] // new subarray
        );
        if(best[i] > ans) ans=best[i];
    }
    // max_element(A,A+n);
    return ans;
}

int kadane2(int *A,int n)
{   
    int oldBest=0; // best[i-1]

    int ans=INT_MIN;
    for(int i=0;i<n;i++) 
    {
        // best[i]=max(
        //     (i-1>=0?best[i-1]:0) + A[i], // old subarray mein continue
        //     A[i] // new subarray
        // );
        int nowBest=max(
            oldBest + A[i], // old subarray mein continue
            A[i] // new subarray
        );

        if(nowBest > ans) ans=nowBest;
        oldBest=nowBest;

    }
    // max_element(A,A+n);
    return ans;
}

int kadane3(int *A,int n)
{   
    int best_sum=0; // best[i-1]

    int ans=INT_MIN;
    for(int i=0;i<n;i++) 
    {
        // best[i]=max(
        //     (i-1>=0?best[i-1]:0) + A[i], // old subarray mein continue
        //     A[i] // new subarray
        // );
        best_sum=max(
            best_sum + A[i], // old subarray mein continue
            A[i] // new subarray
        );

        if(best_sum > ans) ans=best_sum;
    }
    // max_element(A,A+n);
    return ans;
}

int kadane4(int *A,int n)
{   
    int best_sum=0; // best[i-1]

    int ans=INT_MIN;
    for(int i=0;i<n;i++) 
    {
        // best[i]=max(
        //     (i-1>=0?best[i-1]:0) + A[i], // old subarray mein continue
        //     A[i] // new subarray
        // );
        best_sum=best_sum+A[i];

        if(best_sum > ans) ans=best_sum;

        if(best_sum < 0) best_sum=0;
    }
    // max_element(A,A+n);
    return ans;
}

int main()
{
    int n; cin>>n;
    int A[n];

    for(int i=0;i<n;i++) cin>>A[i];
    // cout<<*max_element(A,A+n);


    cout<<kadane1(A,n)<<endl;
    cout<<kadane2(A,n)<<endl;
    cout<<kadane3(A,n)<<endl;
    cout<<kadane4(A,n)<<endl;
    


    // for(int i=0;i<n;i++)
    // {
    //     best=max(best + A[i],A[i]);
    //     ans=max(ans,best[i]);
    // }

    return 0;
}
