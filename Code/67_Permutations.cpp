#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    dp[0] = 1, dp[1] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (i + 1) * dp[i - 1] - (i - 2) * dp[i - 2] - (i - 5) * dp[i - 3] + (i - 3) * dp[i - 4];
        dp[i] %= md;
        dp[i] = (dp[i] + md) % md;
    }
    cout << dp[n];
    return 0;
}