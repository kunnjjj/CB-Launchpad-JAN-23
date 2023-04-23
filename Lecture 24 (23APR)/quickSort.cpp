#include<bits/stdc++.h>
using namespace std;


void quickSort(int *A,int s,int e)
{
    // A[s].....A[e] tak sort karke do
    if(s>=e)
    {
        return ;
    }
    
    int pivot=A[e];
    int idx=s;
    for(int i=s;i<=e-1;i++)
    {
        if(A[i]<=pivot)
        {
            swap(A[i],A[idx]);
            idx++;
        }
    }

    swap(A[idx],A[e]);
    quickSort(A,s,idx-1);
    quickSort(A,idx+1,e);

}
int main()
{   
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    quickSort(A,0,n-1);


    return 0;
}