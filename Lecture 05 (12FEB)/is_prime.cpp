#include <iostream>
using namespace std;

// dataType nameOfFunc(dataType var1,dataType var2,...)
// {
//     /*
//         LOGIC OF YOUR CODE
//     */
//    return val; //
// }

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
    int x = 6;

    x = 10;

    bool res = is_prime(5);
    if (res == true)
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }

    res = is_prime(7);

    return 0;
}