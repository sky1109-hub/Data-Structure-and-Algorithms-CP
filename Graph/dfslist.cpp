#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int n, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> edges;

    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);

    cout << "Enter edges (u v) format (0-based index):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, adjList, visited);
    cout << endl;

    return 0;
}
