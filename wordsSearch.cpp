#include <bits/stdc++.h>
using namespace std;

bool checkWord(vector<vector<char>> &board, string &word, int index, int row, int col)
{

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        return false;

    if (board[row][col] != word[index])
        return false;

    else if (index == word.size() - 1)

        return true;

    char temp = board[row][col];

    board[row][col] = '*';

    if (checkWord(board, word, index + 1, row + 1, col) ||
        checkWord(board, word, index + 1, row - 1, col) ||
        checkWord(board, word, index + 1, row, col + 1) ||
        checkWord(board, word, index + 1, row, col - 1))
    {

        board[row][col] = temp;

        return true;
    }

    board[row][col] = temp;
    return false;
}

// Check duplicate

bool check(vector<string> result, string word)
{
    for (auto x : result)
    {
        if (word == x)
            return true;
    }
    return false;
}
int main()
{
    vector<vector<char>> board =
        {{'C', 'O', 'D', 'T', 'F', 'X'},
         {'K', 'R', 'I', 'R', 'K', 'Z'},
         {'G', 'A', 'N', 'E', 'A', 'T'},
         {'X', 'N', 'G', 'E', 'F', 'O'},
         {'N', 'G', 'M', 'A', 'R', 'T'},
         {'F', 'E', 'K', 'C', 'K', 'L'}};

    int n;
    cout << "\nEnter number of strings: ";
    cin >> n;
    string words[n];
    for (int i = 0; i < n; i++)
        cin >> words[i];
    vector<string> result;
    for (int k = 0; k < n; k++)
    {
        if (check(result, words[k]))
            continue;
        else
        {
            string word = words[k];
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {

                    if (board[i][j] == word[0] && checkWord(board, word, 0, i, j))
                    {

                        result.push_back(word);
                    }
                }
            }
        }
    }
    for (auto x : result)
        cout << x << " ";
    cout << endl;
}