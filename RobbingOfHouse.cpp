#include <bits/stdc++.h>

using namespace std;

int GetMoney(int nums[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;
    int nums[n];
    cout << "Enter the values of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int arr1[n - 1], arr2[n - 1];
    arr1[0] = 0;
    arr2[n - 1] = 0;
    for (int i = 0; i < n; i++)
    {

        if (i != 0)
        {
            arr1[i] = nums[i];
        }

        if (i != n - 1)
        {
            arr2[i] = nums[i];
        }
    }

    int money1 = GetMoney(arr1, n);
    int money2 = GetMoney(arr2, n);
    cout << max(money1, money2) << endl;
}