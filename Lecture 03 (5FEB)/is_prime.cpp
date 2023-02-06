#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i = 1;
    int cnt = 0;
    while (i <= N)
    {
        if (N % i == 0)
        {
            cnt = cnt + 1;
        }
        i = i + 1;
    }

    if (cnt == 2)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }

    return 0;
}