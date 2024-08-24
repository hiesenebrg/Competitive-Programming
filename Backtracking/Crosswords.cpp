#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a word can be placed horizontally
bool canPlaceHorizontally(vector<vector<char> >& board, string word, int row, int col) {
    //word length should not be greataer then width of board
    if (col + word.length() > board[0].size()) return false;
    
    for (int i = 0; i < word.length(); i++) {
        // we are checking on that cell if neither '-' nor the required letter is there, return false
        if (board[row][col + i] != '-' && board[row][col + i] != word[i]) return false;
    }
    
    return true;
}

// Function to check if a word can be placed vertically
bool canPlaceVertically(vector<vector<char> >& board, string word, int row, int col) {
        //word length should not be greataer then height of board

    if (row + word.length() > board.size()) return false;
    
    for (int i = 0; i < word.length(); i++) {
// we are checking on that cell if neither '-' nor the required letter is there, return false

        if (board[row + i][col] != '-' && board[row + i][col] != word[i]) return false;
    }
    
    return true;
}

// Function to place a word horizontally
void placeHorizontally(vector<vector<char> >& board, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        board[row][col + i] = word[i];
    }
}

// Function to place a word vertically
void placeVertically(vector<vector<char> >& board, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        board[row + i][col] = word[i];
    }
}

// Function to remove a word placed horizontally
void removeHorizontally(vector<vector<char> >& board, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        board[row][col + i] = '-';
    }
}

// Function to remove a word placed vertically
void removeVertically(vector<vector<char> >& board, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        board[row + i][col] = '-';
    }
}

// Recursive function to solve the crossword
bool solveCrossword(vector<vector<char> >& board, vector<string>& words, int index) {
    if (index == words.size()) return true;

    string word = words[index];

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (canPlaceHorizontally(board, word, row, col)) {
                placeHorizontally(board, word, row, col);
                if (solveCrossword(board, words, index + 1)) return true;
                removeHorizontally(board, word, row, col);
            }
            
            if (canPlaceVertically(board, word, row, col)) {
                placeVertically(board, word, row, col);
                if (solveCrossword(board, words, index + 1)) return true;
                removeVertically(board, word, row, col);
            }
        }
    }

    return false;
}

// Function to print the board
void printBoard(vector<vector<char> >& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
   vector<vector<char> > board(9, vector<char>(9, '+'));

// Set the '-' positions
board[0][1] = '-';
board[1][1] = '-';
board[1][4] = '-';
board[1][5] = '-';
board[1][6] = '-';
board[2][1] = '-';
board[2][2] = '-';
board[2][3] = '-';
board[2][4] = '-';
board[2][5] = '-';
board[3][5] = '-';
board[4][5] = '-';
board[5][1] = '-';
board[5][2] = '-';
board[5][3] = '-';
board[5][4] = '-';
board[5][5] = '-';
board[5][6] = '-';
board[6][1] = '-';
board[6][4] = '-';
board[6][7] = '-';
board[7][1] = '-';
board[7][2] = '-';
board[7][3] = '-';
board[7][4] = '-';
board[7][5] = '-';
board[8][5] = '-';


 // Initialize the vector of words
    vector<string> words;
    words.push_back("PARIKH");
    words.push_back("ROHAN");
    words.push_back("FOR");
    words.push_back("GO");


    if (solveCrossword(board, words, 0)) {
        printBoard(board);
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
