#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    double s = 0.0, d = pow(k, n);
    for (int i = 0; i < k; i++)
        s += pow(i, n);

    cout << fixed << setprecision(6) << (double)(k - s / d) << endl;

    return 0;
}