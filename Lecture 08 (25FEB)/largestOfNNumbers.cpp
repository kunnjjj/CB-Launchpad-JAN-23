#include<iostream>
#include<climits>
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

    int large=INT_MIN;
    for(int i=0;i<n;i+=1)
    {
        if(A[i] > large) large=A[i];
    }
    cout<<large<<endl;

    return 0;
}