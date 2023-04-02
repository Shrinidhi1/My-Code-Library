#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

char caseToggling(char letter)
{
    int ascii_value = (int)letter;
    int result = ascii_value | 32;
    return (char)result;
}

int main()
{
    string word = "ApPleS", result="";
    int n= word.size();
    for(int i=0; i<n; i++)
    {
        result += caseToggling(word[i]);
    }
    cout << result;
    return 0;
}