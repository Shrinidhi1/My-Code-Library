#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/* Time complexity: O(1)
Auxiliary space: O(1) */
int countBitsSet(int num)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if (num & (1 << i))
            count++;
    }
    return count;
}

/* Time Complexity: O(log n)
Auxiliary Space: O(1) */
int countBitsSet1(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

/* Time Complexity: O(log n)
Auxiliary Space: O(1) */
int countBitsSet2(int num)
{
    int count = 0;
    while (num)
    {
        num &= (num - 1);
        count++;
    }
    return count;
}

int nJobs(vector<vector<int>> cost, int n)
{
    int k = pow(2, n);
    int nj[k], x;
    fill_n(nj, k, INT_MAX);
    nj[0] = 0;
    for (int mask = 0; mask < k; mask++)
    {
        x = countBitsSet(mask);
        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                nj[mask | (1 << j)] = min(nj[mask | (1 << j)], nj[mask] + cost[x][j]);
            }
        }
    }
    return nj[k - 1];
}

int main()
{
    int n = 3;
    vector<vector<int>> matrix{
        {3, 2, 7},
        {5, 1, 3},
        {2, 7, 2}};

    cout << nJobs(matrix, n);
}