#include<iostream>
using namespace std;

int main()
{
    int x=5;
    int y=x++;
    int z=++x;
    int p=++z + ++y;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"z: "<<z<<endl;
    cout<<"p: "<<p<<endl;


    return 0;
}