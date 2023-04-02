#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 6;
int pi[mxN], z[mxN];

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        int j = pi[i - 1];
        while (j && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;

        z[i] = max(0LL, min(z[i - l], r - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    for (int i = 0; i < n; i++)
        cout << z[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << pi[i] << ' ';
    return 0;
}