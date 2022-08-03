#include<iostream>
using namespace std;
 
void create_Zarr(string str, int Z[])
{
    int n = str.length();
    int left, right, k;
    left = right = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > right)
        {
            left = right = i;
            while (right<n && str[right-left] == str[right])
                right++;
            Z[i] = right-left;
            right--;
        }
        else
        {
            k = i-left;
            if (Z[k] < right-i+1)
                Z[i] = Z[k];
            else
            {
                left = i;
                while (right<n && str[right-left] == str[right])
                    right++;
                Z[i] = right-left;
                right--;
            }
        }
    }
}

void find(string text, string pattern)
{

    string concat = pattern + "$" + text;
    int l = concat.length();
    int Z[l];
    create_Zarr(concat, Z);
    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == pattern.length())
            cout << "Pattern found at index "
                << i - pattern.length() -1 << endl;
    }
}
int main()
{
    cout<<"Enter the text:";
    string text ;
    cin>>text;
    cout<<"Enter the pattern to be checked:";
    string pattern;
    cin>>pattern;
    find(text, pattern);
    return 0;
}