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

    for(int row=0;row<=R-1;row++)
    {
        for(int col=C-1;col>=0;col--) 
        {
            cout<<B[row][col]<<" ";
        }
    }

    return 0;
}