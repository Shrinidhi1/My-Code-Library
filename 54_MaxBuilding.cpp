#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                a[j]++;
            else
                a[j] = 0;
        }
        stack<int> st;
        for (int j = 0; j <= m; j++)
        { // pseudo element at end
            while (!st.empty() && a[st.top()] > a[j])
            {
                int s = st.top();
                st.pop();
                int area = a[s] * (st.empty() ? j : j - st.top() - 1);
                mx = max(mx, area);
            }
            if (j < m)
                st.push(j);
        }
    }
    cout << mx;
    return 0;
}