#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Zigzag conversion
void zigzag(int n, string str)
{
    if (n == 1)
    {
        cout << str;
        return;
    }
    else
    {
        string arr[n];
        int len = str.length(), row = 0;
        bool down;
        for (int i = 0; i < len; i++)
        {
            // cout << row;
            arr[row].push_back(str[i]);
            if (row == 0)
                down = true;
            if (row == n - 1)
                down = false;

            down ? row++ : row--;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i];
    }
}
// Main function
int main()
{
    int n;
    string str;
    cout << "\nEnter a string: ";
    cin >> str;
    cout << "\nEnter number of rows: ";
    cin >> n;
    cout << "\nZigzag string is: ";
    zigzag(n, str);
    cout << endl;
}