#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> dp[1 << n];
    dp[0] = {0, k + 1};
    for (int s = 1; s < (1 << n); s++)
    {
        dp[s] = {25, 0};
        for (int i = 0; i < n; i++)
        {
            if (s >> i & 1)
            {
                auto [c, w] = dp[s ^ (1 << i)];
                if (w + a[i] > k)
                {
                    c++;
                    w = min(a[i], w);
                }
                else
                    w += a[i];
                dp[s] = min(dp[s], {c, w});
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
    return 0;
}