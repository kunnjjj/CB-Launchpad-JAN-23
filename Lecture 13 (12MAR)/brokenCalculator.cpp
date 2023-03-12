#include<iostream>
using namespace std;

void multiply(int* fact,int x,int &idx)
{
    int carry=0;
    for(int i=0;i<=idx;i++)
    {
        int res=fact[i] * x + carry;
        fact[i]=res%10;
        carry=res/10;
    }

    while(carry > 0)
    {
        idx++;
        fact[idx]=carry%10;
        carry/=10;
    }
}

int main()
{
    int n; cin>>n;
    int fact[1500]={0};

    fact[0]=1;
    int idx=0;
    for(int x=1;x<=n;x++)
    {
        multiply(fact,x,idx);
    }

    for(int i=idx;i>=0;i--) cout<<fact[i];

    return 0;
}