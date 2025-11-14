#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj;
int n;
vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
int fn(int c, int t)
{
    if (c == t)
    {
        auto it = find(adj[c].begin(), adj[c].end(), c);
        if (*it == c)
            return INT_MAX;
        return 1;
    }
    if (dp[c][t] != -1)
        return dp[c][t];
    int x = 0;
    for (auto it : adj[c])
    {
        x += fn(it, c);
    }
    return dp[c][t] = x;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        vector<int> ans(n);
        adj.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }

        for (int t = 1; t <= n; t++)
        {
            int l = fn(1, t);
            if (l == 0 || l == 1)
                cout << l << " ";
            if (l == 1)
                cout << -1 << " ";
            else
                cout << 2 << " ";
        }
    }
    return 0;
}