#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2505];
int ct = 0;
int ans = 5000;
int vis[2505];

void bfs(int x, int t)
{
    queue<int> q;
    vis[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto i : adj[s])
        {
            if (x == s && i == t)
                continue;
            if (vis[i])
                continue;
            vis[i] = vis[s] + 1;
            if (i == t)
                return;
            q.push(i);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e.push_back({u, v});
    }
    for (auto [i, j] : e)
    {
        memset(vis, 0, sizeof vis);
        bfs(i, j);
        if (vis[j])
            ans = min(ans, vis[j]);
    }
    if (ans < 5000)
        cout << ans;
    else
        cout << -1;
    return 0;
}