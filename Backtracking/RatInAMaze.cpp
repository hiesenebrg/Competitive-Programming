
#include <iostream>
using namespace std;

void printSolution(int **solution, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
         cout << endl;
    }
    cout << endl;
}

void mazeHelp(int maze[][5], int n, int **solution, int x, int y) {
    if (x == n - 1 && y == n - 1) {
        solution[x][y] = 1;
        printSolution(solution, n);
        solution[x][y] = 0;
        return;
    }
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1) {
        return;

    }
    solution[x][y] = 1;   

    // Debugging: Print current position
    mazeHelp(maze, n, solution, x - 1, y);
    mazeHelp(maze, n, solution, x + 1, y);
    mazeHelp(maze, n, solution, x, y - 1);
    mazeHelp(maze, n, solution, x, y + 1);
    solution[x][y] = 0;
}

void ratInAMaze(int maze[][5], int n) {
    int **solution = new int*[n];
    for (int i = 0; i < n; i++) {
        solution[i] = new int[n];
    }
    mazeHelp(maze, n, solution, 0, 0);
}

int main() {
    // int n;
    // cin >> n;

    // int maze[20][20]; // Fixed array size
int maze[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1}
    };
    // Input maze values here

    ratInAMaze(maze, 5);
    return 0;
}