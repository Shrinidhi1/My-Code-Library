#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;

int main()
{
    int k, n;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0, c = 0, ans = 0;
    while (l < n)
    {
        while (r < n && c + (cnt[a[r]] == 0) <= k)
        {
            cnt[a[r]]++;
            c += (cnt[a[r]] == 1);
            r++;
        }
        ans += r - l;
        c -= (cnt[a[l]] == 1);
        cnt[a[l]]--, l++;
    }
    cout << ans;
    return 0;
}