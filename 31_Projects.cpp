#include <bits/stdc++.h>
using namespace std;

struct job
{
    int start, finish, money;
};

bool comp(job j1, job j2) // comparator func used to sort according to the finish times.
{
    return (j1.finish < j2.finish);
}

int find(job a[], int ind) // Find the latest job that comes before the job no. i.
{
    int l = 0, h = ind - 1;

    while (l <= h) // Binary Search
    {
        int mid = (l + h) / 2;
        if (a[mid].finish < a[ind].start)
        {
            if (a[mid + 1].finish < a[ind].start)
                l = mid + 1;

            else
                return mid;
        }

        else
            h = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    struct job a[n];
    for (int i = 0; i < n; i++) // taking input
        cin >> a[i].start >> a[i].finish >> a[i].money;

    sort(a, a + n, comp); // sort based on finish time

    int *dp = new int[n];
    dp[0] = a[0].money;
    for (int i = 1; i < n; i++)
    {
        int temp = a[i].money; // temp = stores money of project i.
        int search = find(a, i);
        if (search != -1)
            temp += dp[search];

        dp[i] = max(dp[i - 1], temp); // store the max between the dp[i-1] and temp
        // we have basically stored the max between 2 cases. i) if project i is included. ii) if project i is excluded.
    }

    cout << dp[n - 1] << endl;
    delete[] dp;
    return 0;
}