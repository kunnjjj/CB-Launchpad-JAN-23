#include<iostream>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    // for(int i=2;i<=n/2;i+=1)
    for (int i = 2; i * i <= n; i += 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int i=2;
    while(i<=100)
    {
        cout<<"val of i: "<<i<<endl;
        i+=5;
        if(i%7==0)
        {
            i+=10;
            continue;
        }
        i-=2;
        if(is_prime(i))
        {
            break;
        }
    }
    cout<<"outside loop: "<<i<<endl;
    cout<<"------------------------------------------------"<<endl;

    for(int i=1;i<=20;i+=1)
    {
        cout<<"val of i in for loop: "<<i<<endl;
        if(i%2==0)
        {
            i+=4;
            continue;
        }
        else
        {
            i+=3;
            continue;
        }
    }



    return 0;
}