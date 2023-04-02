#include <iostream>
#include <algorithm>
using namespace std;

int longestIncSubsequence(int arr[], int n)
{
    int count = 0, res = 0, prev;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            prev = arr[i];
            if (arr[j] > prev)
            {
                count++;
                prev = arr[j];
            }
        }
        res = max(res, count);
        count = 0;
    }
    return res;
}

int longestIncSubsequence1(int arr[], int n)
{
    int LIS[n] = {1};
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    return *max_element(LIS, LIS + n);
}

int main()
{
    int arr[6] = {5, 11, 3, 15, 30, 25};
    cout << "Number of elements in Longest Increasing Subsequence is: " << longestIncSubsequence(arr, 6);
    return 0;
}