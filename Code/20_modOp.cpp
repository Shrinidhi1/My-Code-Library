#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

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

void modOperation(int n, int m)
{
    // Addition
    int add = (n + m) % mod;
    int add1 = (n % mod + m % mod) % mod;
    cout << add << " " << add1 << endl;

    // Subtraction
    int sub = (n - m) % mod;
    int sub1 = ((n % mod) - (m % mod)) % mod;
    cout << sub << " " << sub1 << endl;

    // Multiplication
    int mul = (n * m) % mod;
    int mul1 = ((n % mod) * (m % mod)) % mod;
    cout << mul << " " << mul1 << endl;

    // Division (Fails)
    int div = (n / m) % mod;
    int div1 = ((n % mod) / (m % mod)) % mod;
    cout << div << " " << div1 << endl;

    int inv = findmmi(m, mod);
    int div2 = (n * inv) % mod;
    cout << div2;
}

int main()
{
    int n = 1e7 + 234, m = 1e5 + 178;
    modOperation(n, m);
    return 0;
}