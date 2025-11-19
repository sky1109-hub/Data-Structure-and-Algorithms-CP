#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
using pii = pair<int, int>;
vector<vector<int>> adj;
vector<pii> path;
void bfs(int u, int p, int v)
{
    if (u == v)
    {
        return;
    }
    for (auto it : adj[u])
    {
        if (it != p)
        {
            path.push_back({min(it, u), max(it, u)});
            bfs(it, u, v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        vector<int> p(m);
        for (int i = 0; i < m; i++)
            cin >> p[i];
        sort(p.begin(), p.end());

        adj.resize(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(a, -1, b);
        bfs(b, -1, c);
        struct pair_hash
        {
            size_t operator()(const pair<int, int> &p) const
            {
                return ((size_t)p.first << 32) ^ (size_t)p.second;
            }
        };

        unordered_map<pair<int, int>, int, pair_hash> mp;
        for (auto it : path)
        {
            mp[it]++;
        }
        ll ans = 0, i = 0;
        for (auto it : mp)
        {
            ans += it.second * p[i];
            i++;
        }
        cout << ans<<endl;
    }

    return 0;
}