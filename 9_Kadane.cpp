#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int a[], int size)
{
    int sum = INT_MIN, tsum = 0, start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        tsum += a[i];
        if (sum < tsum)
        {
            sum = tsum;
            start = s;
            end = i;
        }

        if (tsum < 0)
        {
            tsum = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << sum << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end << endl;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    maxSubArraySum(a, n);
    return 0;
}
