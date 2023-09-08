#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int knapsack(int n, int c, int v[], int w[])
{
    if (n == 0 || c == 0)
        return 0;

    if (dp[n][c] != -1)
        return dp[n][c];

    if (c >= w[n - 1])
    {
        /// if item is picked
        int op1 = knapsack(n - 1, c - w[n - 1], v, w) + v[n - 1];
        /// if item is not picked
        int op2 = knapsack(n - 1, c, v, w);

        return dp[n][c] = max(op1, op2);
    }
    else
        return dp[n][c] = knapsack(n - 1, c, v, w);
}

int main()
{
    int n, c;
    cin >> n >> c;
    int w[n], v[n];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= c; ++j)
            dp[i][j] = -1;

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(n, c, v, w);

    return 0;
}