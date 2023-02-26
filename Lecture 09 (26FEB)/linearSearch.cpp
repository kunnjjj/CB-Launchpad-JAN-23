#include<iostream>
using namespace std;

int linearSearch(int *A,int n,int target)
{
    for(int i=0;i<n;i+=1)
    {
        if(A[i]==target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N;
    cin>>N;

    int A[N];

    for(int i=0;i<N;i+=1)
    {
        cin>>A[i];
    }

    int target; 
    cin>>target;

    cout<<linearSearch(A,N,target);
    // int idx=-1;

    // for(int i=0;i<N;i+=1)
    // {
    //     if(A[i]==target)
    //     {
    //         idx=i;
    //         break;
    //     }
    // }
    // cout<<idx;

    return 0;
}