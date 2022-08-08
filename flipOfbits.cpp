#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void flipBits(int n)
{

    int bits = (int)log2(n) + 1;
    cout << (((1 << bits) - 1) ^ n);
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    flipBits(n);
    cout << endl;
    return 0;
}