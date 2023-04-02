#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n - 2);
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    int a[n + 1] = {0};
    for (auto &i : v)
    {
        cin >> i;
        a[i]++;
        if (s.count(i))
            s.erase(i);
    }
    for (int i = 0; i < n - 2; i++)
    {
        int x = *s.begin();
        s.erase(x);
        cout << x << ' ' << v[i] << endl;
        a[v[i]]--;
        if (a[v[i]] == 0)
            s.insert(v[i]);
    }
    cout << *s.begin() << ' ' << *s.rbegin();
    return 0;
}