#include <iostream>
#include <vector>
using namespace std;



void heapify(int i, int N,vector<int> &Priority_queue)
{
    // O(logN)
    int greatest = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    if (left_child < N && Priority_queue[left_child] > Priority_queue[greatest])
    {
        greatest = left_child;
    }

    if (right_child < N && Priority_queue[right_child] > Priority_queue[greatest])
    {
        greatest = right_child;
    }

    if (greatest != i)
    {
        swap(Priority_queue[i], Priority_queue[greatest]);
        heapify(greatest, N,Priority_queue);
    }
}


int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    // change array to MAX heap
    // for(int i=n-1;i>=0;i--)
    // {
    //     heapify(i,n);
    // }

    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(i,n,A);
    }

    for(int N=n;N>=1;N--)
    {
        swap(A[0],A[N-1]);
        int effective_size=N-1;
        heapify(0,effective_size,A);
    }

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
