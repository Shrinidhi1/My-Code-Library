#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int findmmi(int n, int m)
{
    int i = 1;
    while (i < m)
    {
        if ((n * i) % m == 1)
            return i;
        i++;
    }
    return -1;
}

int power(int x, unsigned int y, unsigned int M)
{
    if (y == 0)
        return 1;

    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int fastmmi(int n, int m)
{
    int g = gcd(n, m);
    if (g != 1)
        return -1;
    return power(n, m - 2, m);
}

int main()
{
    int n = 3, m = 11;
    cout << findmmi(n, m) << endl << fastmmi(n, m);
    return 0;
}