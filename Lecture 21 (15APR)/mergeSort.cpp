#include<iostream>
using namespace std;

void merge(int *A,int s,int e)
{
    int mid=(s+e)/2;
    // assume A[s...mid] tak already sorted
    // assume A[mid+1...end] tak already sorted hai

    int C[e-s+1];
    int idx=0;
    int i=s,j=mid+1;
    while(i<=mid && j<=e)
    {
        if(A[i] <= A[j])
        {
            C[idx]=A[i];
            i+=1;
            idx+=1;
        }
        else
        {
            C[idx]=A[j];
            idx++;
            j+=1;
        }
    }

    while(i<=mid)
    {
        C[idx]=A[i];
        i++;
        idx++;
    }
    while(j<=e)
    {
        C[idx]=A[j];
        idx++;
        j++;
    }

    idx=0;
    for(int i=s;i<=e;i++)
    {
        A[i]=C[idx++];
    }
}

void mergeSort(int *A,int s,int e) // your task is to sort A[s]......A[e]
{
    if(s>=e) return ;

    int mid=(s+e)/2; 
    mergeSort(A,s,mid); // bharosa rakhna hai ki ye, A[s....mid] tak sort kardega
    mergeSort(A,mid+1,e); // bharosa ki ye , A[mid+1.....e] tak sort kardega

    merge(A,s,e);
}

int main()
{
    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    mergeSort(A,0,n-1);

    for(int i=0;i<n;i++) cout<<A[i]<<" ";

    return 0;
}