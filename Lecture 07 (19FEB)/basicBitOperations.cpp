#include<iostream>
using namespace std;
int main()
{
    int x=53,y=47;


    cout<<"x&y: "<<(x&y)<<endl;
    cout<<"x|y: "<<(x|y)<<endl;
    cout<<"x^y: "<<(x^y)<<endl;

    cout<<"(x>>2): "<<(x>>2)<<endl;
    cout<<"(x<<2): "<<(x<<2)<<endl;

    int i=3;
    if((x&(1<<i))>0)
    {
        cout<<"ith bit of x was 1"<<endl;
    }
    else
    {
        cout<<"ith bit of x was 0"<<endl;
    }

    if(((x>>i)&1)==1)
    {
        cout<<"ith bit of x was 1"<<endl;
    }
    else
    {
        cout<<"ith bit of x was 0"<<endl;
    }


    return 0;
}