
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

int main()
{
    vector<vector<char>> board = {
        {'C', 'O', 'D', 'K', 'P', 'R'},
        {'G', 'X', 'I', 'L', 'Q', 'Z'},
        {'M', 'T', 'N', 'K', 'O', 'P'},
        {'L', 'K', 'G', 'M', 'A', 'Q'},
        {'c', 'O', 'D', 'K', 'R', 'L'},
        {'c', 'O', 'D', 'K', 'T', 'L'},
    };
    string word = "CODINGMART";
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (board[i][j] == word[0] && checkWord(board, word, 0, i, j))
            {
                cout << "True" << '\n';
                return 0;
            }
        }
    }
    cout << "False" << '\n';
    return 0;
}