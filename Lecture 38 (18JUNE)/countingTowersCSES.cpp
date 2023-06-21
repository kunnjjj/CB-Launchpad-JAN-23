// https://cses.fi/problemset/task/2413


#include <bits/stdc++.h>
using namespace std;
 
int mod_add(int a, int b, int M = (int)1e9 + 7)
{
    return (a % M + b % M) % M;
}
 
int mod_mul(int a, int b, int M = (int)1e9 + 7)
{
    return (a % M * 1LL * b % M) % M;
}
 
int mod_diff(int a, int b, int M = (int)1e9 + 7)
{
    return ((a % M - b % M) % M + M) % M;
}
 
int main()
{
    int t;
    cin >> t;
    int max_n = 1e6;
 
    vector<vector<int>> CNT(max_n + 1, vector<int>(2));
 
    CNT[1][0] = 1;
    CNT[1][1] = 1;
    for (int i = 2; i < (int)CNT.size(); i++)
    {
        // CNT[i][0]
        // total towers of len=i, that
        // do not have a cut in ith block
        // CNT[i][0]=2*CNT[i-1][0] + CNT[i-1][1];
 
        CNT[i][0] = mod_add(mod_mul(2, CNT[i - 1][0]), CNT[i - 1][1]);
 
        // CNT[i][1]
        // total towers of len=i,
        // that have a cut in ith block
        CNT[i][1] = mod_add(CNT[i - 1][0], mod_mul(4, CNT[i - 1][1]));
    }
 
    while (t--)
    {
        int n;
        cin >> n;
 
        cout << mod_add(CNT[n][0], CNT[n][1]) << endl;
    }
    return 0;
}
