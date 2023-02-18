#include<iostream>
using namespace std;


int main()
{

    int i=3;
    int j=10;

    if(i%2==1)
    {
        j+=5;
        cout<<"j is: "<<j<<endl;
    }
    else
    {
        int j=2;
        j+=5;
        cout<<"j is "<<j<<endl;
    }
    i+=6;
    cout<<"j is "<<j<<endl;


    for(int i=1;i<=10;i+=1) if(i%2==0) cout<<i<<" ";







    return 0;
}