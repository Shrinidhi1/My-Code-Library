#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int stolenValue(vector<int> values)
{
    int n = values.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = values[i];
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + values[i - 1]);
    }
    return dp[n];
}

int main()
{
    vector<int> values = {9, 3, 5, 8, 2, 4, 7};
    cout << stolenValue(values);
    return 0;
}