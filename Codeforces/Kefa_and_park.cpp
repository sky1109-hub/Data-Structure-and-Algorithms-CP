#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> c, vis;
vector<vector<int>> adj;
int m = 0;
int dfs(int node, int k,int prev)
{
    if (k > m)
        return 0;
    if (adj[node].size()==1)
    {
        if(adj[node][0]==prev){
           return (k<=m?1:0);
        }
    }
    vis[node] = 1;
    int x = 0;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            x += dfs(it, (c[it] == 1 ? k + 1 : 0),node);
        }
    }
    return x;
}
int main()
{
    int n;
    cin >> n >> m;
    c.resize(n + 1);
    vis.resize(n + 1, 0);
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (adj[1].empty())
    {
        cout << 0;
        return 0;
    }

    cout << dfs(1, c[1],-1);

    return 0;
}