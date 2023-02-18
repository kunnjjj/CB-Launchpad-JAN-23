#include<iostream>
using namespace std;

int main()
{
    int N; cin>>N;

    int m=(N+1)/2;

    // UPPER TRIANGLE

    for(int i=1;i<=m;i+=1)
    {
        // INITIAL SPACES
        for(int j=-4*i + 4*m;j>=1;j-=1)
        {
            cout<<" ";
        }

        // DEC NUMBER
        for(int j=i;j>=1;j-=1)
        {
            cout<<j<<" ";
        }

        // MIDDLE SPACES

        for(int j=4*i-6;j>=1;j-=1)
        {
            cout<<" ";
        }

        if(i!=1)
        {
            // INC NUMBERS
            for(int j=1;j<=i;j+=1)
            {
                cout<<j<<" ";
            }
        }
        
        cout<<endl;
    }



    return 0;
}