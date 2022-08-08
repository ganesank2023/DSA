#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number:\n";
    int number1;
    cin >> number1;
    int temp = number1;
    int lsb = temp & 1;
    cout << "The LSB value of the given number is " << lsb << endl;
    int msb = 0;
    temp = number1;
    temp = temp / 2;
    while (temp != 0)
    {
        temp = temp / 2;
        msb++;
    }
    int res = 1 << msb;
    int bits = (int)log2(res) + 1;
    if (number1 - res <= bits)
        res = 1;
    else
        res = 0;
    cout << "The MSB value of the given number is " << res << endl;
}