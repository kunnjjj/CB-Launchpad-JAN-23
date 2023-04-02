#include<iostream>
using namespace std;

void func(int &a,int b)
{   
    cout<<"address of a: "<<(&a)<<endl; //0x61fef4
    a=15;
}

void func1(int* ptr)
{
    (*ptr)=97;
}

void func3(int *arr)
{

}



int main()
{
    int x=10;

    cout<<"value of x: "<<x<<endl;
    cout<<"address of x: "<<(&x)<<endl; // ADDRESS OF 'x'

    int y=11;
    cout<<"address of y: "<<(&y)<<endl;
    int *ptr=&x; // pointer variable
    float z=3.2;
    float* ptr3=&z;

    cout<<"address of ptr: "<<&ptr<<endl;

    cout<<"value of x with help of ptr: "<<*ptr<<endl;

    int p=10; //0x61fef4
    cout<<"address of p: "<<(&p)<<endl;
    func(p,x);

    int &q=p; // q: reference variable

    cout<<"address of q: "<<(&q)<<endl;
    cout<<q<<endl;

    cout<<"value of p: "<<p<<endl;
    func1(&p);
    cout<<"value of p: "<<p<<endl;

    int A[3]={10,12,19};
    cout<<"address of 0th location: "<<(&A[0])<<endl;
    cout<<"address of 1st location: "<<(&A[1])<<endl;
    cout<<"A: "<<A<<endl;

    char ch[4]={'a','b','c','\0'};

    cout<<(void*)ch<<endl;
    cout<<(void*)&ch[0]<<endl;
    cout<<ch[0]<<endl;

    int B[10]={15,17,19,20,12,15};
    int *ptr2=&B[0];

    (*ptr2)++;
    // idhar 1
    for(int i=0;i<6;i++) cout<<B[i]<<" "; cout<<endl;

    ptr2++;
    // idhar 2
    for(int i=0;i<6;i++) cout<<B[i]<<" "; cout<<endl;
    (*ptr2)--;
    // idhar 3
    for(int i=0;i<6;i++) cout<<B[i]<<" ";cout<<endl;
    ++ptr2;
    ++ptr2;
    (*ptr)=(*ptr)*10;
    // idhar 4
    for(int i=0;i<6;i++) cout<<B[i]<<" ";cout<<endl;

    // idhar 5
    for(int i=0;i<6;i++) cout<<B[i]<<" ";cout<<endl;
    (*ptr)--;




    return 0;
}