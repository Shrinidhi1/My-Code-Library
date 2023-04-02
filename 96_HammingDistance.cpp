#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); j++)
        {
            v[i] += (s[j] == '1') * (1 << j);
        }
    }
    int ans = 32;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, (int)__builtin_popcount(v[i] ^ v[j]));
        }
    }
    cout << ans;
    return 0;
}