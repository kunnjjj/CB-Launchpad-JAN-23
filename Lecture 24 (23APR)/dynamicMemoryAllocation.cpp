#include<iostream>
using namespace std;

int *getArray()
{
    int *A=new int [5];
    A[0]=10;
    A[1]=2;
    A[2]=98;
    A[3]=74;
    A[4]=67;
    return A;
}

int main()
{

    int *A=getArray();

    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<" ";
    }
    int n; cin>>n;
    

    // int B[n];
    int *B=new int[n];
    


    // int A[5];
    // int x,y,z; // ...

    // cout<<(&x)<<endl;

    // func();

    // int *ptr=new int;

    // float* ptr2=new float;

    // int *ptr3=new int [5];

    // double* ptr4=new double [3];

    // int *B=new int[5];

    return 0;
}