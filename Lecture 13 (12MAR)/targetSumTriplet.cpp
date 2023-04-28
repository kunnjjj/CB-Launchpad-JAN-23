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

    for(int fix=0;fix<n;fix++)
    {
        int newTarget=target-A[fix];
        int i=fix+1,j=n-1;
        while(i<j)
        {
            if(A[i] + A[j]==newTarget)
            {
                cout<<A[fix]<<", "<<A[i]<<" and "<<A[j]<<endl;
                i++;
                j--;
            }
            else if(A[i] + A[j] > newTarget)
            {
                j--;
            }
            else 
            {
                i++;
            }
        }
    }

    return 0;
}