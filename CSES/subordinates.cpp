#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj;
vector<int> ans;
int dfs(int node)
{
    if (adj[node].empty())
    {
        return 0;
    }
    int k =0;
    for (auto it : adj[node])
    {
        k += dfs(it);
    }
    ans[node] = k + 1;
    return k + 1;
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
    int x = dfs(1);
    for (int i = 1; i <= n; i++)
        cout <<( ans[i]) << " ";

    return 0;
}