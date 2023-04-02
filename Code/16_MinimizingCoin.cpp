#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int minimizingCoin(vector<int> coins, int k)
{
    vector<int> dp(k + 1, 0);
    int n = coins.size();
    for (int i = 1; i <= k; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[k] >= INT_MAX ? -1 : dp[k];
}

int main()
{
    vector<int> coins = {1, 5, 7};
    cout << minimizingCoin(coins, 11);
    return 0;
}