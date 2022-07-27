#include <iostream>
using namespace std;
int main()
{
    int n, m, m1, n1, total;
    cout << "\nInput the number of rows : ";
    cin >> m;
    cout << "\nInput the number of columns : ";
    cin >> n;
    m1 = m;
    n1 = n;
    total = m1 * n1;
    int arr[m][n];
    int arr2[m1 * n1];
    int arr3[m1][n1];
    int i, j;
    cout << "\nInput the matrix \n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "\nThe Matrix is \n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSpiral Matrix : ";
    int k = 0, l = 0, index = 0;
    while (k < m && l < n)
    {
        // Right to left
        for (i = l; i < n; i++)
        {
            cout << arr[k][i] << " ";
            arr2[index] = arr[k][i];
            index++;
        }
        k++;
        // Top to bottom
        for (i = k; i < m; i++)
        {
            cout << arr[i][n - 1] << " ";
            arr2[index] = arr[i][n - 1];
            index++;
        }
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= 0; --i)
            {
                cout << arr[m - 1][i] << " ";
                arr2[index] = arr[m - 1][i];
                index++;
            }
            m--;
        }

        if (l < n)
        {
            for (i = m - 1; i >= k; i--)
            {
                cout << arr[i][l] << " ";
                arr2[index] = arr[i][l];
                index++;
            }
            l++;
        }
    }
    cout << endl;
    cout
        << "\nArray in Matrix fromat" << endl;
    i = 0;
    while (i < total)
    {
        for (j = 0; j < m1; j++)
        {
            for (int k = 0; k < n1; k++)
            {
                arr3[j][k] = arr2[i];
                i++;
            }
        }
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
            printf("%2d ", arr[i][j]);
        cout
            << endl;
    }
    cout << endl;
    return 0;
}
