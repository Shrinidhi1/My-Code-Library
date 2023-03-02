#include <iostream>
#include <cmath>
using namespace std;

int josephProblem1(int n)
{
    return 2 * (n - pow(2, floor(log2(n)))) + 1;
}

int countBits(int n)
{
    return (int)log2(n) + 1;
}

int josephProblem2(int n, int bits)
{
    return (n >> 1) | (n << (bits - 1));
}

int main()
{
    int n;
    cin >> n;
    int k = countBits(n);
    cout << "Person surviving is: " << josephProblem2(n, k);
    return 0;
}