// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int INF = 1e9;
// using pii = pair<int, int>;
// vector<vector<int>> adj;
// vector<pii> path;
// void bfs(int u, int p, int v)
// {
//     if (u == v)
//     {
//         return;
//     }
//     for (auto it : adj[u])
//     {
//         if (it != p)
//         {
//             path.push_back({min(it, u), max(it, u)});
//             bfs(it, u, v);
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, a, b, c;
//         cin >> n >> m >> a >> b >> c;

//         vector<int> p(m);
//         for (int i = 0; i < m; i++)
//             cin >> p[i];
//         sort(p.begin(), p.end());

//         adj.resize(n + 1);

//         for (int i = 0; i < m; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             adj[x].push_back(y);
//             adj[y].push_back(x);
//         }
//         bfs(a, -1, b);
//         bfs(b, -1, c);
//         struct pair_hash
//         {
//             size_t operator()(const pair<int, int> &p) const
//             {
//                 return ((size_t)p.first << 32) ^ (size_t)p.second;
//             }
//         };

//         unordered_map<pair<int, int>, int, pair_hash> mp;
//         for (auto it : path)
//         {
//             mp[it]++;
//         }
//         ll ans = 0, i = 0;
//         for (auto it : mp)
//         {
//             ans += it.second * p[i];
//             i++;
//         }
//         cout << ans;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<ll> dist(n, INF);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        a--, b--, c--;

        vector<ll> p(m);
        for (int i = 0; i < m; i++)
            cin >> p[i];
        sort(p.begin(), p.end());

        vector<ll> pref(m + 1, 0);
        for (int i = 0; i < m; i++)
            pref[i + 1] = pref[i] + p[i];

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        // BFS from a, b, c
        vector<ll> da = bfs(a, adj);
        vector<ll> db = bfs(b, adj);
        vector<ll> dc = bfs(c, adj);

        ll ans = INF;

        for (int v = 0; v < n; v++) {
            ll dab = da[v];
            ll dbb = db[v];
            ll dcb = dc[v];

            
            if (dab == INF || dbb == INF || dcb == INF) continue;
            if (dab + dbb + dcb > m) continue;

            ll cost = pref[dbb] + pref[dab + dbb + dcb];
            ans = min(ans, cost);
        }

        cout << ans << "\n";
    }

    return 0;
}
//Very short version

// Sort weights and compute prefix sum.

// BFS from a, b, c → get distances da, db, dc.

// For each node v:

// compute edges required: da[v] + db[v] + dc[v]

// ensure ≤ m

// cost = pref[db[v]] + pref[da[v] + db[v] + dc[v]]

// Minimum cost is the answer.