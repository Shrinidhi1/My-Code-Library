#include <iostream>
#include <vector>

using namespace std;

int LCS(string s1, string s2)
{
    int l1 = s1.size(), l2 = s2.size();
    int lcs[l1 + 1][l2 + 1] = {};
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[l1][l2];
}

int main()
{
    string s1 = "abcda", s2 = "bdabac";
    cout << LCS(s1, s2);
    return 0;
}
