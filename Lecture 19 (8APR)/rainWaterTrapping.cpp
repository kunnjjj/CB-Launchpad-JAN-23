#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    int left_max=A[0],right_max=A[n-1];
    int i=0,j=n-1;
    int ans=0;
    while(i<j)
    {
        left_max=max(left_max,A[i]);
        right_max=max(right_max,A[j]);
        if(left_max<=right_max)
        {
            // min(left[i],right[i])-A[i]
            ans+=left_max-A[i];
            i++;
        }
        else
        {
            ans+=right_max-A[j];
            j--;
        }
    }
    cout<<ans<<endl;

    // int left[n];

    // left[0]=A[0];
    // for(int i=1;i<n;i++)
    // {
    //     left[i]=max(left[i-1],A[i]);
    // }

    // int right[n];
    // right[n-1]=A[n-1];
    // for(int i=n-2;i>=0;i--)
    // {
    //     right[i]=max(right[i+1],A[i]);
    // }

    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans+=min(left[i],right[i])-A[i];
    // }
    // cout<<ans<<endl;



    return 0;
}