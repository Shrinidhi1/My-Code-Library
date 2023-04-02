#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 27;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (char s : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (s - '0')] + 1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}