#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
int c = 0;

void dfs(int node, int par)
{
    for (int it : adj[node])
    {
        if (it == par) continue;

        dfs(it, node);

       
        if (!vis[node] && !vis[it])
        {
            vis[node] = vis[it] = 1;
            c++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    cout << c << endl;
}
