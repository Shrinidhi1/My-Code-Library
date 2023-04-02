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

int main()
{
    int n, m;
    cin >> n >> m;
    // burnside's lemma
    // no. of objects = avg. no of symmetrical pictures over all symmetries.
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + exp(m, __gcd(i, n), md)) % md;
    }
    ans = ans * exp(n, md - 2, md) % md;
    cout << ans;
    return 0;
}