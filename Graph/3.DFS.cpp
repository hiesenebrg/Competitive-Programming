#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &currTraversal) {
    visited[node] = 1;
    currTraversal.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, currTraversal);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);  // Adjacency list
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);  // Because the graph is undirected
    }

    vector<int> visited(V, 0);
    vector<vector<int>> ans;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> currTraversal;
            dfs(i, adj, visited, currTraversal);
            ans.push_back(currTraversal);
        }
    }

    return ans;
}
