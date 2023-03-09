#include<iostream>
using namespace std;

void print(int *A,int n)
{
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}

void insertionSort(int *A,int n)
{
    for(int i=1;i<=n-1;i++)
    {
        int cur=A[i];
        int j=i-1;
        while(j>=0 && cur < A[j])
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=cur;
    }

}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    insertionSort(A,n);
    print(A,n);


    return 0;
}