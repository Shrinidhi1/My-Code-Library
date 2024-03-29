#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
int gap, N;
string S;

bool comp(int x, int y)
{
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix()
{
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1)
    {
        sort(sa, sa + N, comp);
        for (int i = 0; i < N - 1; i++)
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

void build_lcp()
{
    for (int i = 0, k = 0; i < N; i++)
        if (pos[i] != N - 1)
        {
            int j = sa[pos[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            lcp[pos[i]] = k;
            if (k)
                k--;
        }
}

int main()
{
    cin >> S;
    N = S.size();
    suffix();
    build_lcp();
    int k;
    cin >> k;
    int prev = 0;
    int cur = 0;
    for (int i = 0; i < N; i++)
    {
        if (cur + (N - sa[i]) - prev >= k)
        {
            int j = prev;
            string ans = S.substr(sa[i], j);
            while (cur < k)
            {
                ans += S[sa[i] + j];
                cur++;
                j++;
            }
            return cout << ans, 0;
        }
        cur += (N - sa[i]) - prev;
        prev = lcp[i];
    }
    return 0;
}