#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int ca = 0;
int n = 18;
int arr[] = {0, 1, 1, 0, 2, 3, 4, 1, 3, 5, 1, 5, 3, 5, 4, 0, 2, 2};

int main()
{
    int left, right;
    cin >> left >> right;
    int maxe = *max_element(arr, arr + n);
    vector<int> count(maxe + 1, 0);
    int mo_right = 0, mo_left = -1;

    auto add = [&](int x)
    {
        ca -= count[x] * count[x] * x;
        count[x]++;
        ca += count[x] * count[x] * x;
    };

    auto remove = [&](int x)
    {
        ca -= count[x] * count[x] * x;
        count[x]--;
        ca += count[x] * count[x] * x;
    };

    while (mo_right < right)
    {
        mo_right++;
        add(arr[mo_right]);
    }
    while (mo_right > right)
    {
        remove(arr[mo_right]);
        mo_right--;
    }
    while (mo_left < left)
    {
        remove(arr[mo_left]);
        mo_left++;
    }
    while (mo_left > left)
    {
        mo_left--;
        add(arr[mo_left]);
    }

    cout << ca;
    return 0;
}