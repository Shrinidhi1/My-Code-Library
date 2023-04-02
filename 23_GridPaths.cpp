#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    string grids[n] = {"....", ".*..", "...*", "*..."}, s;
    int mod = 1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        s = grids[i];
        for (int j = 0; j < n; j++)
        {
            if (s[j] != '*')
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
            else
                dp[i][j] = 0;
        }
    }

    cout << (n > 0 ? (dp[n - 1][n - 1] % mod) : -1);

    return 0;
}