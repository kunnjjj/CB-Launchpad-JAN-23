#include<bits/stdc++.h>
using namespace std;


void func(int** A,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int r,c; cin>>r>>c;

    // int *ptr=new int[4]
    // dataType* ptr= new dataType[size]

    int **A=new int*[r];

    for(int i=0;i<r;i++)
    {
        A[i]=new int [c];
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>A[i][j];
        }
    }



    func(A,r,c);

    cout<<A[2][3]<<endl;

    cout<< *((*(A+2)+3))<<endl;

    int x=2,y=3;
    cout<<A[x][y]<<endl;
    cout<<*((*(A+x) + y))<<endl;

    for(int i=0;i<r;i++)
    {
        delete[](A[i]);
    }
    delete[](A);

    // BELOW CODE WILL GIVE JUNK VALUES
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}