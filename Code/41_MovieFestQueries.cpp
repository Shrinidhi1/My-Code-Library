#include <bits/stdc++.h>
using namespace std;

int dp[1000006][25];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[y][0] = max(dp[y][0], x);
    }
    for (int i = 1; i <= 1000000; i++)
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);

    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= 1000000; i++)
            dp[i][k] = dp[dp[i][k - 1]][k - 1];

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        while (y > 0)
        {
            int z = 0;
            for (int i = 0; i <= 20; i++)
            {
                if (dp[y][i] < x)
                {
                    z = i;
                    break;
                }
            }

            if (z == 0)
                break;
            ans += (1 << (z - 1));
            y = dp[y][z - 1];
        }
        cout << ans << endl;
    }
    return 0;
}