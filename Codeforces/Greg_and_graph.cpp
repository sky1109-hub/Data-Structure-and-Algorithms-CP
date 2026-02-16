
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    vector<int> x(n), used(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i]--;
    }
    vector<ll> ans;
    reverse(x.begin(), x.end());
    for (int t = 0; t < n; t++)
    {
        int k = x[t];
        used[k] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            if (used[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (used[j])
                    {
                        s += dist[i][j];
                    }
                }
            }
        }
        ans.push_back(s);
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    return 0;
}