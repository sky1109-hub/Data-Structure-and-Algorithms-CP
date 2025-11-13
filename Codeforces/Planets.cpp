#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<vector<pii>> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<vector<int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (x--)
        {
            int k;
            cin >> k;
            arr[i].push_back(k);
        }
    }

    int ans = 0;
    vector<int> vis(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});
    vector<int> dis(n + 1, INT_MAX);
    dis[1] = 0;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int d = x.first;
        int node = x.second;

        if (vis[node])
            continue;
        vis[node] = 1;

        
        auto &s = arr[node];
        if (!s.empty())
        {
            auto it = lower_bound(s.begin(), s.end(), d);
            if (it != s.end() && *it == d)
            {
                int i = it - s.begin();
                while (i + 1 < s.size() && s[i + 1] - s[i] == 1)
                    i++;
                d = s[i] + 1; 
            }
        }

        for (auto it : adj[node])
        {
            int x = it.first, wt = it.second;
            if (!vis[x])
            {
                if (d + wt < dis[x])
                {
                    dis[x] = d + wt;
                    pq.push({dis[x], x});
                }
            }
        }
    }

    cout << (dis[n] == INT_MAX ? -1 : dis[n]);
    return 0;
}
