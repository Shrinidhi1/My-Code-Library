#include <bits/stdc++.h>
using namespace std;

const int mxN = 200005;
int bit[mxN];

void upd(int k)
{
    for (; k < mxN; k += k & -k)
        bit[k] += 1;
}
int qry(int k)
{
    int sm = 0;
    for (; k > 0; k -= k & -k)
        sm += bit[k];
    return sm;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    // index compression
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int ct = 0;
    for (auto i : v)
        mp[i] = ++ct;

    int inv[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = qry(ct) - qry(mp[a[i]]);
        upd(mp[a[i]]);
    }
    memset(bit, 0, sizeof bit);
    int ans = 0;
    // position of element is decided by the number of inversions
    // i.e. whether inversions are less on left or right
    for (int i = 0; i < n; i++)
    {
        int x = qry(ct) - qry(mp[a[i]]);
        upd(mp[a[i]]);
        ans += min(x, inv[i]);
    }
    cout << ans;
    return 0;
}