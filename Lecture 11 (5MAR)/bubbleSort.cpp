#include <iostream>
using namespace std;

void print(int *A,int n)
{
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}

void bubbleSort(int *A, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {   
        for (int j = 0; j <= n - 2 -i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
        cout<<i<<"th pass: "<<endl;
        print(A,n);
    }
}

void bubbleSortOptimised(int *A,int n)
{
    for (int i = 0; i <= n - 2; i++)
    {   
        bool swapped=false;
        for (int j = 0; j <= n - 2 -i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                swapped=true;
            }
        }
        
        cout<<i<<"th pass: "<<endl;
        print(A,n);
        if(swapped==false)
        {
            break;
        }
    }
}



int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    bubbleSortOptimised(A,n);
    print(A,n);

    return 0;
}