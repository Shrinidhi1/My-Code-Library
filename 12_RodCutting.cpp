#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void rodCut(vector<int> rod)
{
    int n = rod.size();
    vector<int> dp(n + 2);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 2] = rod[i];
    }
    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    for (int i = 0; i < n + 2; i++)
    {
        cout << dp[i] << " ";
    }
}

int main()
{
    vector<int> rod = {2, 3, 0, 0, 0, 0, 0, 0};
    rodCut(rod);
    return 0;
}