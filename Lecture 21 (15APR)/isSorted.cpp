#include<iostream>
using namespace std;

bool is_sorted(int i,int n,int *A) // return true if A[i].....A[n-1] is sorted, false other wise
{
    if(i==n-1)
    {
        return true;
    }
    if(A[i]<=A[i+1])
    {
        return is_sorted(i+1,n,A);
    }
    else
    {
        return false;
    }
}

bool is_sorted_2(int k,int *A) //return true if first k elements are sorted, otherwise returns false
{
    if(k==1)
    {
        return true;
    }
    
    if(A[k-2] <= A[k-1])
    {
        return is_sorted_2(k-1,A);
    }
    return false;
}

int main()
{


    is_sorted_2(n,A);


    return 0;
}