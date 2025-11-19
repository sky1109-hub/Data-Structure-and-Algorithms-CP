#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;

vector<int> bfs(int start) {
    vector<int> dist(n+2, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    cin >> n;
    adj.resize(n+2);

    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Step 1: BFS from 1 -> find A
    vector<int> d1 = bfs(1);
    int A = max_element(d1.begin(), d1.end()) - d1.begin();

    // Step 2: BFS from A -> find B (diameter)
    vector<int> distA = bfs(A);
    int B = max_element(distA.begin(), distA.end()) - distA.begin();
    int diameter = distA[B];

    // Step 3: BFS from B
    vector<int> distB = bfs(B);

    // Now each query (adding node n+1 and connecting to i)
    for(int i=1;i<=n;i++){
        int new_diameter = max({diameter, distA[i] + 1, distB[i] + 1});
        cout << new_diameter << endl;
    }

    return 0;
}
//Classic fact:

// Start BFS/DFS from any node, get the farthest node → call it A

// BFS/DFS from A, get the farthest node → call it B

// Path A ↔ B is the tree’s unique longest path

// So A and B are the diameter endpoints.