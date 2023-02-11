#include<iostream>
using namespace std;

int main()
{

    int n; 
    cin>>n;

    for(int i=n;i>=1;i-=1)
    {
        for(int j=1;j<=i;j=j+1)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------------------"<<endl;

    for(int i=1;i<=n;i+=1)
    {
        for(int j=n-i;j>=1;j=j-1)
        {
            cout<<"  ";
        }
        for(int j=1;j<=i;j=j+1) 
        {
            cout<<j<<" ";
        }
        for(int j=i-1;j>=1;j=j-1)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }



    return 0;
}

// kunj    arora
// cout<<"\t";