#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string twosComplement(string binary)
{
    string invStr = "";
    int n = binary.size();
    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '0')
            invStr += '1';
        else
            invStr += '0';
    }
    string result = "";
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = (invStr[i] - '0') + carry;
        carry = (sum >= 2) ? 1 : 0;
        result = to_string(sum % 2) + result;
    }
    if (carry)
        result = '1' + result;
    return result;
}

string binaryAnd(string str1, string str2)
{
    string result;
    for (int i = 0; i < str1.length(); ++i)
    {
        if (str1[i] == '1' && str2[i] == '1')
            result += "1";
        else
            result += "0";
    }
    return result;
}

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0, base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int firstOccurrence(string binary)
{
    string neg = twosComplement(binary);
    string res = binaryAnd(binary, neg);
    int res_dec = binaryToDecimal(res);
    return log10(res_dec) / log10(2) + 1;
}
int main()
{
    string binary = "1010";
    cout << firstOccurrence(binary);
    return 0;
}