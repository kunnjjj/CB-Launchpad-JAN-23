#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int A[n]; // although works but should be avoided because this type of
    // declaration is static memory allocation

    for(int i=0;i<n;i+=1)
    {
        cin>>A[i];
    }

    for(int i=n-1;i>=0;i-=1)
    {
        cout<<A[i]<<" ";
    }

    

    return 0;
}