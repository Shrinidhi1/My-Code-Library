#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
int dp[mxN];

int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] < a[i])
            return cout << dp[i - 1], 0;
        dp[i] = dp[i - 1] + a[i];
    }
    cout << dp[n];
    return 0;
}