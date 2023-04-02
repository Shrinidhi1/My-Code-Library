#include <bits/stdc++.h>
using namespace std;

const int mxN = 500005;
const int md = 1e9 + 7;
int dp[mxN];
int ind[26];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    memset(ind, -1, sizeof ind);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1];
        if (ind[s[i - 1] - 'a'] >= 0)
            dp[i] -= dp[ind[s[i - 1] - 'a']];

        dp[i] = (dp[i] + md) % md;
        ind[s[i - 1] - 'a'] = i - 1;
    }
    cout << (dp[n] - 1 + md) % md;
    return 0;
}