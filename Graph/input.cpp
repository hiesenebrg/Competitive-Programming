#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    // adjencency matrix - take space of O(n^2);

    // vector<vector<int>> adjMatrix(n, vector<int>(n, 0)); 
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adjMatrix[u][v] = 1; // Assuming 0-based indexing
    //     adjMatrix[v][u] = 1; // For undirected graph , mak it 0 for directed graph
    // }

    //adjacency list - take space of only O(2m);

    vector<vector<int>> adjList(n + 1); // Change to vector of vectors
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Assuming 1-based indexing
        adjList[v].push_back(u); // For undirected graph, remove this line for directed graph
    }
    cout<< "Adjacency List:" << endl;   
    for (int i = 1; i <= n; i++) // Changed loop to start from 1 to n
    {
        cout << i<<":"<<" ";
        for (int j : adjList[i]) // Iterate through elements of adjList[i]
        {
            cout << j << " "; // Print each element
        }
        cout << endl;
    }
}
