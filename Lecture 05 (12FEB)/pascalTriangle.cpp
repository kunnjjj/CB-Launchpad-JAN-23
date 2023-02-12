#include<iostream>
using namespace std;

int fact(int num)
{
    int prod=1;
    for(int i=1;i<=num;i+=1)
    {
        prod=prod*i;
    }
    return prod;
}

int nCr(int n,int r)
{
    int numerator=fact(n);
    int deno=fact(r) * fact(n-r);
    return numerator/deno;
}

int main()
{
    int n; cin>>n;

    for(int i=0;i<=n-1;i+=1)
    {
        for(int j=0;j<=i;j+=1)
        {
            cout<<nCr(i,j)<<"\t";
        }
        cout<<endl;
    }
    return 0;
}