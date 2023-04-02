#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, x = 10;
    vector<int> price = {4, 8, 5, 3}, page = {5, 12, 8, 1};

    int a, b;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            // option1 = book number i-1 is not included, hence no pages added.
            // option2 = book number i-1 is included, hence pages are added.
            // option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            // option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]); // max of both the boxes included in dp[i][j].
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}