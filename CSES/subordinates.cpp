#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj;
vector<int> ans;

int dfs(int node)
{
    if (adj[node].empty())
    {
        ans[node] = 0; // leaf has 0 subordinates
        return 1;      // subtree size = 1
    }

    int k = 0;
    for (auto it : adj[node])
    {
        k += dfs(it);
    }

    ans[node] = k;   // <-- FIX: store number of subordinates (not k+1)
    return k + 1;    // subtree size = (all children) + itself
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
