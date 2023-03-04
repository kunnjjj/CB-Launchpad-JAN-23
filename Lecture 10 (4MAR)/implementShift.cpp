#include<iostream>
using namespace std;

void shift(int *A,int n)
{
    int temp=A[0];
    for(int i=1;i<n;i+=1)
    {
        A[i-1]=A[i];
    }
    A[n-1]=temp;
}

void reverse(int *A,int s,int e)
{
    int i=s,j=e;
    while(i<j)
    {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i+=1;
        j-=1;

    }
}

void shiftKTimes(int *A,int n,int k)
{
    // k=k%n; 
    k%=n;
    for(int i=1;i<=k;i+=1)
    {
        shift(A,n);
    }
}

// HW: APPROACH USING O(K) space
void shiftKTimesOptimised(int *A,int n,int k)
{
    k%=n;
    reverse(A,0,n-1);
    reverse(A,0,n-k-1);
    reverse(A,n-k,n-1);
}

int main()
{   
    int n; cin>>n;
    int k; cin>>k;
    int A[n];
    for(int i=0;i<n;i+=1) cin>>A[i];

    // shiftKTimes(A,n,k);
    shiftKTimesOptimised(A,n,k);
    for(int i=0;i<n;i+=1) cout<<A[i]<<" ";


    return 0;
}