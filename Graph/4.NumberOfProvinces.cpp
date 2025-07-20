#include <vector>
using namespace std;

// DFS traversal from a given node
void dfsTraversal(int node, vector<vector<int>>& roads, int n, vector<int>& is_visited) {
    is_visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (roads[node][i] && !is_visited[i]) {
            dfsTraversal(i, roads, n, is_visited); 
        }
    }
}

// Main function to find number of provinces
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int ans = 0;
    vector<int> is_visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!is_visited[i]) {
            ans++;
            dfsTraversal(i, roads, n, is_visited);
        }
    }

    return ans;
}
