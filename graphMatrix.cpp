#include <iostream>
using namespace std;

int main()
{
    int n, u, v, m;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "\nEnter number of edges: ";
    cin >> m;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "\nEnter source: ";
        cin >> u;
        cout << "\nEnter destination: ";
        cin >> v;
        arr[u - 1][v - 1] = 1;
        arr[v - 1][u - 1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}