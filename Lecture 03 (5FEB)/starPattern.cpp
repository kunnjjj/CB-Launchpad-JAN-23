#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i=1;
    while(i<=N)
    {
        int space=N-i;
        int j=1;
        while(j<=space)
        {
            cout<<" ";
            j=j+1;
        }
        j=1;
        while(j<=i)
        {
            cout<<"*";
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }



    return 0;
}