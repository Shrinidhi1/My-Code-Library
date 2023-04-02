#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> cost;
    vector<int> val;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    // conversion to 0-1 knapsack
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        int x = 1;
        while (b[i] - x >= 0)
        {
            cost.push_back(x * a[i]);
            val.push_back(x * c[i]);
            b[i] -= x;
            x *= 2;
        }
        if (b[i])
        {
            cost.push_back(b[i] * a[i]);
            val.push_back(b[i] * c[i]);
        }
    }
    n = cost.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j > 0; j--)
        {
            if (j >= cost[i])
                dp[j] = max(dp[j], val[i] + dp[j - cost[i]]);
        }
    }
    cout << dp[x];
    return 0;
}