#include<iostream>
using namespace std;

int main()
{
    int R,C;
    cin>>R>>C;
    int B[R][C];


    for(int row=0; row<=R-1;row++)
    {
        for(int col=0;col<=C-1;col++)
        {
            cin>>B[row][col];
        }
    }
    if(5)
    {
        cout<<"niharika"<<endl;
    }

    if(0)
    {
        cout<<"lakshay"<<endl;
    }

    for(int col=0;col<C;col++)
    {
        if(col&1) // col no. is odd
        {
            for(int row=R-1;row>=0;row--) // rows in dec order
            {
                cout<<B[row][col]<<" ";
            }
        }
        else
        {
            for(int row=0;row<=R-1;row++) // row in inc order
            {
                cout<<B[row][col]<<" ";
            }
        }
    }

    return 0;
}