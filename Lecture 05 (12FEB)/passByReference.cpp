#include<iostream>
using namespace std;

void change1(int n)
{
    n=10;
}

void change2(int &x)
{
    x=10;
}

int main()
{
    int n=5;

    change1(n);

    cout<<"value of n after change1 function: "<<n<<endl;

    change2(n);

    cout<<"value of n after change2 function: "<<n<<endl;



    return 0;
}