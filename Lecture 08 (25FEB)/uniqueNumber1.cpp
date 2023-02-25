#include<iostream>
using namespace std;

int main()
{
    int N; cin>>N;
    int ans=0;
    for(int i=0;i<N;i+=1)
    {
        int x; cin>>x;
        ans=(ans^x);
    }

    cout<<ans<<endl;

    return 0;
}