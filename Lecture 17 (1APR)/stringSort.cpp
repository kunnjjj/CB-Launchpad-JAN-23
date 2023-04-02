#include<iostream>
#include<algorithm>
using namespace std;

bool comp(string &a,string &b)
{
    for(int i=0;i<(int)min(a.size(),b.size()); i++)
    {
        if(a[i] < b[i])
        {
            return true;
        }
        else if(b[i] < a[i])
        {
            return false;
        }
    }
    if(a.size() > b.size()) return true;
    return false;
}

int main()
{
    int n; cin>>n;
    // int A[n];
    string A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A,A+n,comp);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }

    return 0;
}