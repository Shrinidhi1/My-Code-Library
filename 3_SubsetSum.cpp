#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int subsetSum(int arr[], int n, int sum)
{
    vector<vector<int>> SS(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        SS[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (SS[i - 1][j] == 1)
                SS[i][j] = 1;

            else if (arr[i - 1] > j)
                SS[i][j] = 0;

            else
                SS[i][j] = SS[i - 1][j - arr[i - 1]];
        }
    }

    return SS[n][sum];
}

int main()
{
    int n = 4;
    int array[n] = {2, 3, 5, 7};
    int sum = 9;

    if (subsetSum(array, n, sum))
        cout << "Subset exists.";
    else
        cout << "No Subset exists";
    return 0;
}