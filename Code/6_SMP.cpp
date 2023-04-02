#include <bits/stdc++.h>
using namespace std;

#define N 4

bool wPrefersM1OverM(int prefer[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
            return false;
    }
    return true;
}

void stableMarriage(int prefer[2 * N][N])
{
    int women_partner[N];
    bool men_free[N];

    memset(women_partner, -1, sizeof(women_partner));
    memset(men_free, false, sizeof(men_free));
    int free_cnt = N;

    while (free_cnt > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (men_free[m] == false)
                break;

        for (int i = 0; i < N && men_free[m] == false; i++)
        {
            int w = prefer[m][i];

            if (women_partner[w - N] == -1)
            {
                women_partner[w - N] = m;
                men_free[m] = true;
                free_cnt--;
            }

            else
            {
                int m1 = women_partner[w - N];

                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    women_partner[w - N] = m;
                    men_free[m] = true;
                    men_free[m1] = false;
                }
            }
        }
    }

    cout << "Woman : Man" << endl;
    for (int i = 0; i < N; i++)
        cout << " " << i + N << "\t" << women_partner[i] << endl;
}

int main()
{
    int ranking[2 * N][N] = {
        {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(ranking);

    return 0;
}