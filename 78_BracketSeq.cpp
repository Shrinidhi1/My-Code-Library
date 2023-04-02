#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
int exp(int x, int y, int md)
{
    int ans = 1;
    x = x % md;
    while (y > 0)
    {
        if (y & 1)
            ans = ans * x % md;
        y = y >> 1;
        x = x * x % md;
    }
    return ans;
}

const int mxN = 2e6 + 6;
int F[mxN], I[mxN];

int main()
{
    // catalan
    int n;
    cin >> n;
    if (n & 1)
        return cout << 0, 0;
    n >>= 1;
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < mxN; i++)
    {
        F[i] = F[i - 1] * i % md;
        I[i] = exp(F[i], md - 2, md);
    }
    int ans = F[2 * n] * I[n] % md * I[n] % md;
    ans = ans * exp(n + 1, md - 2, md) % md;
    cout << ans;
    return 0;
}
