// https://hack.codingblocks.com/app/contests/1236/146/problem
#include <bits/stdc++.h>
using namespace std;

#define LL long long

long long knapsack_01(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<LL>> &dp)
{
    // If I am current on ith item, and have 'W' weight remaining
    // then what is the total max I can get
    if (i == (int)wt.size())
    {
        return 0;
    }

    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }

    long long op1 = 0, op2 = 0;

    // do not choose current item
    op1 = knapsack_01(i + 1, W, wt, val, dp);

    // choose current item and call on it again
    if (W >= wt[i])
    {
        op2 = val[i] + knapsack_01(i, W - wt[i], wt, val, dp);
    }
    return dp[i][W] = max(op1, op2);
}

// knapsack_01(i,W)
// KNAPSACK[i][w]

int main()
{
    int n;
    cin >> n;
    int W;
    cin >> W;

    vector<int> wt(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    // for (int i = 0; i < n; i++)
    //     cin >> wt[i] >> val[i];

    // vector<vector<LL>> dp(n,vector<LL> (W+1,-1));
    // cout<<knapsack_01(0,W,wt,val,dp);
    vector<vector<LL>> KNAPSACK(n + 1, vector<LL>(W + 1));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 0; w <= W; w++)
        {
            long long op1 = 0, op2 = 0;

            // do not choose current item
            // op1 = knapsack_01(i + 1, W, wt, val, dp);
            op1 = KNAPSACK[i + 1][w];

            // choose current item
            if (w >= wt[i])
            {
                op2 = val[i] + KNAPSACK[i][w - wt[i]];
                // op2 = val[i] + knapsack_01(i, W - wt[i], wt, val, dp);
            }
            KNAPSACK[i][w] = max(op1, op2);
        }
    }

    cout << KNAPSACK[0][W] << endl;

    return 0;
}