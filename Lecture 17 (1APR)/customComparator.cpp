#include<iostream>
#include<algorithm>
using namespace std;

int sumOfDigits(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;
}
bool comp(int a,int b)
{
    int sumOfDigitsA=sumOfDigits(a);
    int sumOfDigitsB=sumOfDigits(b);
    return sumOfDigitsA < sumOfDigitsB;
    // if(sumOfDigitsA < sumOfDigitsB)
    // {
    //     return true;
    // }
    // else return false;
}

int main()
{
    int A[5]={0,12,9,13,17};
    int n=5;
    sort(A,A+n,comp);

    for(int i=0;i<n;i++) cout<<A[i]<<" ";

    return 0;
}