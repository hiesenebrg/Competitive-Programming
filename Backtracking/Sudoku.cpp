#include <iostream>
#include <vector>

using namespace std;

bool is_safe(vector<vector<int> > &board, int row, int col, int num)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[start_row + i][start_col + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isValueZero(vector<vector<int> > &board, int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row =i;
                col =j;
                return true;
            }
        }
    }
    return false;
}
bool solve_sudoku(vector<vector<int> > &board)
{
    
    int row, col;
    if (!isValueZero(board, row, col)) //this will  update row ,col and return true
    //if there there is no space to fill 
    {
        return true;
    }
        for (int num = 1; num <= 9; num++)
        {
            if (is_safe(board, row, col, num))
            {
                board[row][col] = num;
                bool noSpaceLeft = solve_sudoku(board);
                if (noSpaceLeft)
                {
                    return true;
                }
                board[row][col] = 0; // Backtrack
            }
        }
        return false;
    

return true;
}

void print_sudoku(vector<vector<int> > &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int> > board(9, vector<int>(9, 0));

    // Example initialization:
    board[0][0] = 3;
    board[0][2] = 6;
    board[0][3] = 5;
    board[0][5] = 8;
    board[0][6] = 4;
    board[1][0] = 5;
    board[1][1] = 2;
    board[2][1] = 8;
    board[2][2] = 7;
    board[2][7] = 3;
    board[2][8] = 1;
    board[3][2] = 3;
    board[3][4] = 1;
    board[3][7] = 8;
    board[4][0] = 9;
    board[4][3] = 8;
    board[4][4] = 6;
    board[4][5] = 3;
    board[4][8] = 5;
    board[5][1] = 5;
    board[5][4] = 9;
    board[5][6] = 6;
    board[6][0] = 1;
    board[6][1] = 3;
    board[6][6] = 2;
    board[6][7] = 5;
    board[7][7] = 7;
    board[7][8] = 4;
    board[8][2] = 5;
    board[8][3] = 2;
    board[8][5] = 6;
    board[8][6] = 3;
    cout << "This is the input sudou -" << endl;
    print_sudoku(board);
    cout << endl;
    if (solve_sudoku(board))
    {
        cout << "This is the response -" << endl;
        print_sudoku(board);
    }
    else
    {
        cout << "No solution" << endl;
    }
    return 0;
}
