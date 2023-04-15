#include<iostream>
using namespace std;


int main()
{
    int n,m; cin>>n>>m;
    int A[n],B[m];

    for(int i=0;i<n;i++) cin>>A[i];

    for(int j=0;j<m;j++) cin>>B[j];

    int C[n+m];

    int idx=0,i=0,j=0;
    while(i<n && j<m)
    {
        if(A[i] <= B[j])
        {
            C[idx]=A[i];
            i+=1;
            idx+=1;
        }
        else
        {
            C[idx]=B[j];
            j+=1;
            idx+=1;
        }
    }

    while(i<n)
    {
        C[idx]=A[i];
        i++;
        idx++;
    }

    while(j<m)
    {
        C[idx]=B[j];
        j++;
        idx++;
    }

    for(int i=0;i<n+m;i++)
    {
        cout<<C[i]<<" ";
    }

    return 0;
}