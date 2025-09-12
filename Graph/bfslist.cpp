#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>> &adjList, vector<bool> &visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    cout << "BFS Traversal: ";
    bfs(start, adjList, visited);
    cout << endl;

    return 0;
}
