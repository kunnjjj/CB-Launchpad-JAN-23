#include<iostream>
#include<algorithm>
using namespace std;


bool canCowsBePlaced(int *stalls,int N,int C,int minDist)
{   
    // stalls[0]
    C--;
    int nextReqdCor=stalls[0] + minDist;

    for(int i=1;i<N;i++)
    {
        if(stalls[i]>=nextReqdCor)
        {
            C--;
            nextReqdCor=stalls[i] + minDist;
            if(C==0) // all cows have been placed
            {
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int N,C; cin>>N>>C;
    int stalls[N];
    for(int i=0;i<N;i++) cin>>stalls[i];

    sort(stalls,stalls+N);
    int ans=0;
    // for(int minDist=1;minDist<=(stalls[N-1]-stalls[0]);minDist++) // O(MAX-MIN)
    // {
    //     if(canCowsBePlaced(stalls,N,C,minDist)) // O(N)
    //     {
    //         ans=minDist;
    //     }
    //     else break;
    // }
    // O((MAX-MIN)*N)

    int s=1,e=(stalls[N-1]-stalls[0]);
    while(s<=e) // O(log(MAX-MIN))
    {
        int mid=(s+e)/2; // s + (e-s)/2
        if(canCowsBePlaced(stalls,N,C,mid)) //O(N)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }

    // O(N*log(MAX-MIN)) =10^5 * log(10^9)=10^5*(3.5)*9 <=2*10^8
    cout<<ans<<endl;
}

int main()
{   
    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}