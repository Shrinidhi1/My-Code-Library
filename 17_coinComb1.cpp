#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int coinComb1(vector<int> coins, int x)
{
    int n = coins.size();
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] += dp[i - coins[j]];
            dp[i] %= mod;
        }
    }

    return dp[x];
}

int main()
{
    vector<int> coins = {2, 3, 5};
    cout << coinComb1(coins, 9);
    return 0;
}