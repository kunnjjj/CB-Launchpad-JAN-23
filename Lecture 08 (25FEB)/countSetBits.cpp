#include <iostream>
using namespace std;

int countSetBits(int N)
{
    int cnt = 0;

    while (N > 0)
    {
        cnt += (N & 1);
        N >>= 1;
    }
    return cnt;
}
int main()
{
    int N;
    cin >> N;
    cout << "set bits in N: " << countSetBits(N) << endl;

    return 0;
}