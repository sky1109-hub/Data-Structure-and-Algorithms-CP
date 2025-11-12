
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }// key idea:find distance of every type of product from node i
    
    vector<vector<int>> dis(k + 1, vector<int>(n + 1, INT_MAX));
    for (int t = 1; t <= k; t++)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == t)
            {
                q.push(i);
                dis[t][i] = 0;
            }
        }
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dis[t][node] != INT_MAX && 1 + dis[t][node] < dis[t][it])
                {
                    dis[t][it] = 1 + dis[t][node];
                    q.push(it);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp;
        for (int t = 1; t <= k; t++)
        {
            temp.push_back(dis[t][i]);
        }
        sort(temp.begin(), temp.end());
        int ans = 0;
        for (int j = 0; j < s; j++)
            ans += temp[j];
        cout << ans << " ";
    }
    return 0;
}