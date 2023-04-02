#include<iostream>
using namespace std;

int main()
{
    char a,b,c,d; 
    a=cin.get();
    b=cin.get();
    c=cin.get();
    d=cin.get();

    // cin>>a>>b>>c;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cout<<"d: "<<d<<endl;
    char arr[6]={'P','R','A','B','H','\0'};

    char arr2[10]="PRABH";

    cout<<"arr: "<<arr<<endl;
    cout<<"arr2: "<<arr2<<endl;

    char arr3[10];
    arr3[0]='P';
    arr3[1]='R';
    arr3[2]='A';
    arr3[3]='\0';
    cout<<arr3<<endl;



    return 0;
}