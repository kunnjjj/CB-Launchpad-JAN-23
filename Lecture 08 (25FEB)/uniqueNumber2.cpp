#include<iostream>
using namespace std;

int kaunsiBit(int N)
{
    //0........30 
    int ans=-1;
    for(int i=0;i<=30;i+=1)
    {
        if((N>>i)&1==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    int A[n];
    int XOR=0;

    for(int i=0;i<n;i+=1) 
    {
        cin>>A[i];
        XOR=(XOR^A[i]);
    }

    int spl_bit=kaunsiBit(XOR); // 1

    int ans1=0,ans2=0;
    for(int i=0;i<n;i++)
    {
        if((A[i]>>spl_bit)&1==1)
        {
            ans1=(ans1^A[i]);
        }
        else
        {
            ans2=(ans2^A[i]);
        }
    }
    // if(ans1<ans2)
    // {
    //     cout<<ans1<<" "<<ans2<<endl;
    // }
    // else
    // {
    //     cout<<ans2<<" "<<ans1<<endl;
    // }
    cout<<min(ans1,ans2)<<" "<<max(ans1,ans2)<<endl;
    return 0;
}