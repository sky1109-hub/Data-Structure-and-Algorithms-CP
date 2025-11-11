#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<ll> d(n + 1, LLONG_MAX);
    vector<int> par(n + 1);
    for(int i = 1; i <= n; i++) par[i] = i;

    d[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 1});

    vector<bool> vis(n + 1, false);

    while(!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if(vis[u]) continue; 
        vis[u] = true;

        for(auto &[v, w] : adj[u]) {
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                par[v] = u;
                pq.push({d[v], v});
            }
        }
    }

    if(d[n] == LLONG_MAX) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for(int cur = n; cur != par[cur]; cur = par[cur])
        path.push_back(cur);
    path.push_back(1); 

    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
}
