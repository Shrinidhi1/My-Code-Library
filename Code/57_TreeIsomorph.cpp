#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> mp;
int idx = 0;

int dfs(int s, int p, vector<int> adj[])
{
    vector<int> v;
    for (auto i : adj[s])
    {
        if (i != p)
            v.push_back(dfs(i, s, adj));
    }
    sort(v.begin(), v.end());
    if (!mp.count(v))
        mp[v] = idx++;
    return mp[v];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> adj1[n + 1], adj2[n + 1];
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            adj1[x].push_back(y);
            adj1[y].push_back(x);
        }
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
        int s1 = dfs(1, -1, adj1);
        int s2 = dfs(1, -1, adj2);
        if (s1 == s2)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}