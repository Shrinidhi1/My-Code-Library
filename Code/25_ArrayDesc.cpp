#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int arrayDesc(vector<int> &v, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (v[i] == 0 || v[i] == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (v[i] == 0 || v[i] == j)
                    dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % mod + dp[i - 1][j + 1]) % mod;
                else
                    dp[i][j] = 0;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        res += dp[n][i];
        res %= mod;
    }

    return res;
}

int main()
{
    int n = 3, m = 5;

    vector<int> v(n + 1);
    v[1] = 2;
    v[2] = 0;
    v[3] = 2;
    // for(int i=1; i<=n; i++)
    //     cin >> v[i];

    cout << arrayDesc(v, n, m) << endl;
    return 0;
}