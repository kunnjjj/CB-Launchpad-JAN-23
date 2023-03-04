#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double eps=1e-10;
    if(abs((0.1 + 0.2)-0.3)<eps)
    {
        cout<<"equal";
    }
    else
    {
        cout<<"unequal";
    }

    return 0;
}