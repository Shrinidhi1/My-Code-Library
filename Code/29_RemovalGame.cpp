#include <bits/stdc++.h>
#include <vector>
#define s 5005
using namespace std;

int n = 4;
int dp[s][s], a[] = {4, 5, 1, 3};

int fun(int i, int j)
{

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursion case
    int op1 = a[i] + min(fun(i + 2, j), fun(i + 1, j - 1));
    int op2 = a[j] + min(fun(i + 1, j - 1), fun(i, j - 2));

    return dp[i][j] = max(op1, op2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << fun(0, n - 1) << endl;

    return 0;
}