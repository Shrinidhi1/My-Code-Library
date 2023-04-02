#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int gamingArray(vector<int> arr)
{
    int peak = 0;
    bool bob = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > peak)
        {
            bob = !bob;
            peak = arr[i];
        }
    }
    return bob ? 1 : 2;
}

int gamingArray1(vector<int> arr)
{
    int count = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] < arr[i])
            count++;
    }
    if (count % 2 == 1)
        return 1;
    return 0;
}

int main()
{
    vector<int> arr = {2, 3, 5, 4, 1};
    cout << gamingArray(arr) << endl;
    cout << gamingArray1(arr) << endl;
    return 0;
}