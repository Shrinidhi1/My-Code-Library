#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (s.size() > 1)
    {
        auto x = s.begin();
        s.erase(x);
        auto y = s.begin();
        s.erase(y);
        ans += *x + *y;
        s.insert(*x + *y);
    }
    cout << ans;
    return 0;
}