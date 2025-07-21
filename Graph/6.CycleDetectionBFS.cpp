#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<vector<int>> &adj, vector<int> &is_visited) {
    queue<pair<int, int>> q; // {node, parent}
    q.push({start, -1});
    is_visited[start] = 1;

    while (!q.empty()) {
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[currNode]) {
            if (!is_visited[neighbor]) {
                is_visited[neighbor] = 1;
                q.push({neighbor, currNode});
            } else if (neighbor != parent) {
                return true; // cycle detected
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    vector<vector<int>> adj(n); // Create adjacency list
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    vector<int> is_visited(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!is_visited[i]) {
            if (bfs(i, adj, is_visited)) {
                return "YES";
            }
        }
    }

    return "NO";
}
