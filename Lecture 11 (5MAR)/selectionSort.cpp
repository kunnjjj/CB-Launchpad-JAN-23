#include <iostream>
using namespace std;

void print(int *A,int n)
{
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}

void selectionSort(int *A,int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int minIdx=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(A[j] < A[minIdx])
            {
                minIdx=j;
            }
        }
        swap(A[i],A[minIdx]);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];


    selectionSort(A,n);
    print(A,n);

    return 0;
}