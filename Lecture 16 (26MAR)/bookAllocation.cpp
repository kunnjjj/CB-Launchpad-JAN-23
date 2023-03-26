#include<iostream>
using namespace std;

bool canBeReadByStudents(int* books,int N,int S,int maxPages) 
{
    //maxPagesdenotes in the worst case how many books will be assigned to a student
    // OUR GOAL IS to minimise this maxPages
    int cur_sum=0;
    int cur_stu=1;

    for(int i=0;i<N;i++)
    {
        if(cur_sum+books[i]<=maxPages)
        {
            cur_sum+=books[i];
        }
        else
        {
            cur_stu++;
            if(cur_stu > S)
            {
                return false;
            }
            cur_sum=books[i];
        }
    }
    return true;

}

void solve()
{
    int N,S; cin>>N>>S;
    int books[N];
    int maxElement=0,sum=0;
    for(int i=0;i<N;i++) 
    {
        cin>>books[i];
        maxElement=max(maxElement,books[i]);
        sum+=books[i];
    }
    int ans=1e9;
    // for(int maxPages=maxElement;maxPages<=sum;maxPages++) // O(SUM-MAX)
    // {
    //     if(canBeReadByStudents(books,N,S,maxPages)) // O(N)
    //     {
    //         ans=maxPages;
    //         break;
    //     }
    // }
    // O(N*(SUM-MAX))

    int s=maxElement,e=sum;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(canBeReadByStudents(books,N,S,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    
    cout<<ans<<endl;


}
int main()
{
    int t; cin>>t;
    while(t--) solve();


    return 0;
}