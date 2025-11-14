#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int diameterVal = 0;

int dfs(int u, int parent)
{
    priority_queue<int> pq;

    for (int v : adj[u])
    {
        if (v == parent) continue;

        int depth = 1 + dfs(v, u);
        pq.push(depth);
    }

    if (pq.empty())  
        return 0;

    if (pq.size() == 1)
        return pq.top();

    int x = pq.top(); pq.pop();
    int y = pq.top();

    diameterVal = max(diameterVal, x + y);

    return x;
}

int main()
{
    int n;
    cin >> n;

    adj.resize(n + 1);

    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
    int root = 1;

    int longestDown = dfs(root, -1);

    cout << max(longestDown, diameterVal) * 3 << endl;

    return 0;
}
