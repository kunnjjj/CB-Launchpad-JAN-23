#include<iostream>
using namespace std;

int main()
{   
    int n; cin>>n;
    for(int i=1;i<=n;i=i+1)
    {
        for(int combo=n-i;combo>=1;combo-=1)
        {
            cout<<" ";
            cout<<"\t";
        }
        for(int j=i;j<=2*i-1;j+=1)
        {
            cout<<j;
            cout<<"\t";
        }
        for(int j=2*i-2;j>=i;j-=1)
        {
            cout<<j;
            cout<<"\t";
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i=i-1)
    {
        for(int combo=n-i;combo>=1;combo-=1)
        {
            cout<<" ";
            cout<<"\t";
        }
        for(int j=i;j<=2*i-1;j+=1)
        {
            cout<<j;
            cout<<"\t";
        }
        for(int j=2*i-2;j>=i;j-=1)
        {
            cout<<j;
            cout<<"\t";
        }
        cout<<endl;
    }

    return 0;
}