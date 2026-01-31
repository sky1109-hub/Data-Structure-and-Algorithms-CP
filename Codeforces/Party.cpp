#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int node, int c)
{
    if (adj[node].empty())
    {
        return c;
    }
    int k = 0;
    for (auto it : adj[node])
    {
        k = max(k, dfs(it, c + 1));
    }
    return k;
}

int main()
{
    ll n;
    cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
            continue;
        adj[x].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans = max(ans, dfs(i, 1));
        }
    }

    cout << ans << endl;
    return 0;
}
