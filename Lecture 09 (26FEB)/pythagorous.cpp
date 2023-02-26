#include <iostream>
using namespace std;

int main()
{
    long long side;
    cin >> side;

	long long side2,side3;

    if (side % 2 == 0)
    {
        long long m = (side / 2);
        long long n = 1;

        side2=m*m-n*n;
        side3=m*m+n*n;
    }
    else
    {
        long long m = (side + 1) / 2;
        long long n = (side - 1) / 2;
         
        side2=2*m*n;
        side3=m*m+n*n;
    }
    if(side2>0 && side3>0 && (side*side + side2*side2==side3*side3))
    {
        cout<<side2<<" "<<side3<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}