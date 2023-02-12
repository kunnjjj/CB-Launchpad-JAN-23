#include<iostream>
using namespace std;



int main()
{
    int n; cin>>n;

    for(int i=0;i<=n-1;i+=1)
    {
        int prod=1;
        cout<<prod<<"\t"; //j=0 
        for(int j=1;j<=i;j+=1)
        {
            prod*=(i-j+1);
            prod/=j;
            cout<<prod<<"\t";
        }
        cout<<endl;
    }
    return 0;
}