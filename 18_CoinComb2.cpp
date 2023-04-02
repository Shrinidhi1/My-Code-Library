#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int coinComb2(vector<int> coins, int x)
{
    int n = coins.size();
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // ways to achieve sum of 0,using the array = 1, i.e = taking a null subset.

    for (int i = 0; i < n; i++) // we take each coin specifically, and do the needed calculations
    {
        for (int j = 0; j <= x; j++) // we build numbers from 0 to sum, using the taken coin i.e- coin[i]
        {
            if (j - coins[i] >= 0)
            {
                dp[j] += dp[j - coins[i]];
                dp[j] %= mod;
            }
        }
    }
    return dp[x];
}

int main()
{
    vector<int> coins = {2, 3, 5};
    cout << coinComb2(coins, 9);
    return 0;
}
