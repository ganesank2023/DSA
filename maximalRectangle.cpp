#include <bits/stdc++.h>
using namespace std;

int R, C;
int maxHist(int row[])
{

    stack<int> result;

    int top_val;

    int max_area = 0;

    int area = 0;

    int i = 0;
    while (i < C)
    {

        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else
        {

            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }

    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}

int main()
{

    cout << "\nEnter number of row: ";
    cin >> R;
    cout << "\nEnter number of columns: ";
    cin >> C;

    int A[R][C];
    cout << "\nEnter the values of the matrix" << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cin >> A[i][j];
    }
    cout << "\nArea of maximum rectangle is ";

    int result = maxHist(A[0]);

    for (int i = 1; i < R; i++)
    {

        for (int j = 0; j < C; j++)

            if (A[i][j])
                A[i][j] += A[i - 1][j];

        result = max(result, maxHist(A[i]));
    }
    cout << result << endl;
    return 0;
}
