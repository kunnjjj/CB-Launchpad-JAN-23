#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

    int n; cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    sort(A,A+n);
    int target; cin>>target;

    int i=0,j=n-1;
    while(i<j)
    {
        if(A[i] + A[j]==target)
        {
            cout<<A[i]<<" and "<<A[j]<<endl;
            i++;
            j--;
        }
        else if(A[i]+ A[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}