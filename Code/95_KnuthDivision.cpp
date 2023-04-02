#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3 + 5;
pair<int, int> dp[mxN][mxN];
int pre[mxN];
const int INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    for (int i = 1; i < n; i++)
        dp[i][i + 1] = {pre[i + 1] - pre[i - 1], i};

    for (int k = 3; k <= n; k++)
    {
        for (int i = 1; i + k - 1 <= n; i++)
        {
            int j = i + k - 1;
            pair<int, int> p = {dp[i][j - 1].second, dp[i + 1][j].second};
            dp[i][j] = {INF, -1};
            for (int x = p.first; x <= p.second; x++)
                dp[i][j] = min(dp[i][j], {dp[i][x].first + dp[x + 1][j].first, x});
            dp[i][j].first += pre[j] - pre[i - 1];
        }
    }
    cout << dp[1][n].first;
    return 0;
}