#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 6;
int spf[mxN];

void sieve()
{
    spf[0] = 1;
    for (int i = 1; i < mxN; i++)
        spf[i] = i;
    for (int i = 2; i * i < mxN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < mxN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int cnt[mxN];

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    sieve();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> v;
        while (x > 1)
        {
            int y = spf[x];
            v.push_back(y);
            while (x % y == 0)
                x /= y;
        }
        int k = v.size();
        for (int s = 1; s < (1 << k); s++)
        {
            int p = 1;
            for (int j = 0; j < k; j++)
            {
                if (s >> j & 1)
                {
                    p *= v[j];
                }
            }
            int sgn = -1;
            if (__builtin_popcount(s) & 1)
                sgn = 1;
            ans += sgn * cnt[p];
            cnt[p]++;
        }
    }
    cout << n * (n - 1) / 2 - ans;
    return 0;
}