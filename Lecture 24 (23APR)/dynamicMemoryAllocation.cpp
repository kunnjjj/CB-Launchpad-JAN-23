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

    int C[]={10,12,10,13};

    cout<<C[2]<<endl;
    cout<<*(C+2)<<endl;
    int *p=&C[0]; // int* p= C;
    cout<<p[2]<<endl; 

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

    int *ptr=new int;

    float* ptr2=new float;

    int *ptr3=new int [5];

    double* ptr4=new double [3];

    int *Z=new int[5];

    delete(ptr);
    delete(ptr2);
    delete(ptr3);
    delete[](ptr4);
    delete[](Z);
    delete[](A);
    delete[](B);

    cout<<endl;

    // for(int i=0;i<5;i++) cout<<A[i]<<" ";
    // cout<<endl;

    int *t=new int [5];
    t=new int[10]; // WE DO NOT HAVE ADDRESS OF OLD 5 buckets, but they exist in memory, this is called memory leak

    return 0;
}