#include <bits/stdc++.h>
using namespace std;

unsigned int swapBitsInPair(unsigned int x)
{
    return ((x & 0xAAAAAAAA) >> 1) |
           ((x & 0x55555555) << 1);
}

int main()
{
    unsigned int x = 4;
    cout << swapBitsInPair(x) << endl;
    return 0;
}
