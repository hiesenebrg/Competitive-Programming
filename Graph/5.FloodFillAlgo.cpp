#include <vector>
using namespace std;

void dfsWay(vector<vector<int>> &image, int x, int y, int oldColor, int newColor, vector<vector<int>> &is_visited) {
    int n = image.size();
    int m = image[0].size();

    is_visited[x][y] = 1;
    image[x][y] = newColor;

    int deltaI[] = {-1, 0, 1, 0};
    int deltaY[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int row = x + deltaI[i];
        int col = y + deltaY[i];

        if (row >= 0 && row < n && col >= 0 && col < m &&
            !is_visited[row][col] && image[row][col] == oldColor) {
            dfsWay(image, row, col, oldColor, newColor, is_visited);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    int oldColor = image[x][y];
    if (oldColor == newColor) return image;  // No change needed

    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> is_visited(n, vector<int>(m, 0));

    dfsWay(image, x, y, oldColor, newColor, is_visited);
    return image;
}
