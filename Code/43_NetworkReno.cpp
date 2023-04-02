#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> v;

void dfs(int s, int p)
{
    for (auto i : adj[s])
    {
        if (i != p)
            dfs(i, s);
    }
    if (adj[s].size() == 1)
        v.push_back(s);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int k = v.size();
    if (k & 1)
        v.push_back(v[0]), k++;
    cout << k / 2 << endl;
    for (int i = 0; i < k / 2; i++)
        cout << v[i] << ' ' << v[i + k / 2] << endl;
    return 0;
}