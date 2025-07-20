#include <vector>
#include <queue>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> is_visited(n, vector<int>(m, 0));  // Initialize visited matrix

    // Push all initially rotten oranges into the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                is_visited[i][j] = 2;
            }
        }
    }

    int max_time = 0;
    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        q.pop();

        max_time = max(max_time, time);

        for (int i = 0; i < 4; i++) {
            int row = r + deltaRow[i];
            int col = c + deltaCol[i];

            if (row >= 0 && row < n && col >= 0 && col < m &&
                is_visited[row][col] != 2 && grid[row][col] == 1) {
                q.push({{row, col}, time + 1});
                is_visited[row][col] = 2;
            }
        }
    }

    // Check if any fresh orange is left
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1 && is_visited[i][j] != 2)
                return -1;

    return max_time;
}
