#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);     // Tracking visited nodes
    vector<int> ans;               // Result of BFS traversal
    queue<int> q;                  // Queue for BFS

    q.push(0);                     // Start BFS from node 0
    visited[0] = 1;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);

        for (int neighbor : adj[currNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }

    return ans;
}
