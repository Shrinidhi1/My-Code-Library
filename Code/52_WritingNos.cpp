#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k)
{
    int ans = 0;
    for (int i = 1; i <= n; i *= 10)
    {
        int d = i * 10;
        ans += n / d * i + min(max(n % d - i + 1, 0LL), i);
    }
    if (ans <= k)
        return 1;
    return 0;
}

int main()
{
    int k;
    cin >> k;
    int l = 1, h = 6e17;
    int ans = 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (check(m, k))
        {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }
    cout << ans;
    return 0;
}