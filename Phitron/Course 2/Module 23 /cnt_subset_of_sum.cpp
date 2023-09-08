#include <bits/stdc++.h>
using namespace std;

int cnt;

/// task: store subsets
vector<vector<int>> subsets;

int subsetCnt(int n, int sum, int setArray[])
{
    if (sum == 0)
        return ++cnt;
    if (n == 0)
        return cnt;

    if (sum >= setArray[n - 1])
    {
        int choiceTake = subsetCnt(n - 1, sum - setArray[n - 1], setArray);

        int choiceNotTake = subsetCnt(n - 1, sum, setArray);

        return max(choiceTake, choiceNotTake);
    }

    else
        return subsetCnt(n - 1, sum, setArray);
}

int main()
{
    int n;
    cin >> n;
    int setArray[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> setArray[i];
    }

    int targetSum = 0;
    cin >> targetSum;
    cout << subsetCnt(n, targetSum, setArray) << endl;

    return 0;
}

/*
--------
Testcase
--------
Input:
4
4 1 2 3
10
Output:
1

Input:
5
1 5 7 9 3
17
Output:
2

Input:
4
1 2 4 6
7
Output:
2

*/