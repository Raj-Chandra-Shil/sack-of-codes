#include <bits/stdc++.h>
using namespace std;

int main()
{
    int capacity, items;
    cin >> items;

    vector<int> values(items), weights(items);

    for (int j = 0; j < items; ++j)
        cin >> values[j];

    for (int i = 0; i < items; ++i)
        cin >> weights[i];

    cin >> capacity;

    int dp[items + 1][capacity + 1];
    for (int i = 0; i <= items; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            /// this is similar to the recursive base case
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= items; ++i)
    {
        for (int j = 1; j <= capacity; ++j)
        {
            if (j >= weights[i - 1])
            {
                /* int op1 = dp[i - 1][j - weights[i - 1]] + values[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2); */

                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[items][capacity] << endl;

    return 0;
}