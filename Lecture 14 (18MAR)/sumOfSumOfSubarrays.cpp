#include<iostream>
using namespace std;

int bruteForce(int *A,int n) // O(n^3)
{
    int sum=0;
    for(int L=0;L<n;L++)
    {
        for(int R=L;R<n;R++)
        {
            for(int i=L;i<=R;i++)
            {
                sum+=A[i];
            }
        }
    }
    return sum;
}

int prefixSumApp(int *A,int n)
{
    int prefix[n];

    for(int i=0;i<n;i++)
    {
        // if(i==0)
        // {
        //     prefix[i]=A[i]; //i=0;
        // }
        // else
        // {
        //     prefix[i]=prefix[i-1] + A[i];
        // }
        prefix[i]=(i==0?A[i]: prefix[i-1] + A[i]);
        // prefix[i]=(i-1>=0?prefix[i-1]+ A[i]:A[i]);
    }

    int sum=0;
    for(int L=0;L<n;L++)
    {
        for(int R=L;R<n;R++)
        {
            // for(int i=L;i<=R;i++)
            // {
            //     sum+=A[i];
            // }
            sum+=(prefix[R] - (L-1>=0?prefix[L-1]:0));

        }
    }
    return 0;
}

int contributionTechnique(int *A,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int left=(i+1),right=(n-i);
        ans+= A[i] * left * right;
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    int A[n];

    for(int i=0;i<n;i++) cin>>A[i];

    cout<<bruteForce(A,n);


    return 0;
}

// TERNARY OPERATOR
// bool found=true;

// int x;

// if(found==true)
// {
//     x=5;
// }
// else
// {
//     x=7;
// }

// x= (condition? yadi True : yadi False)
// x= (found==true?5:7)

