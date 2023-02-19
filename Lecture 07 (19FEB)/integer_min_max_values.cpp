#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int x;
    cout<<"sizeof(x): "<<sizeof(x)<<endl; // kitni space x variable memory mein lega (bytes)

    cout<<"INT_MAX: "<<INT_MAX<<endl;
    cout<<"INT_MIN: "<<INT_MIN<<endl;

    // 2'147'483'647
    long long y;

    cout<<"sizeof(y): "<<sizeof(y)<<endl;
    cout<<"LLONG_MAX: "<<LLONG_MAX<<endl;
    cout<<"LLONG_MIN: "<<LLONG_MIN<<endl;


    cout<<"INT_MAX+1: "<<(INT_MAX+1)<<endl;

    return 0;
}