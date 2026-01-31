#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;

    vector<string> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> ind(26, 0);
    vector<vector<int>> adj(26);
    for (int i = 0; i < n - 1; i++)
    {
        string s = w[i], t = w[i + 1];
        int l = min(s.size(), t.size());
        bool diff = false;
        for (int j = 0; j < l; j++)
        {
            if (s[j] != t[j])
            {
                diff = true;
                adj[s[j]-'a'].push_back(t[j]-'a');
                ind[t[j] - 'a']++;
                break;
            }
        }
        if (!diff && s.size() > t.size())
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    string ans = "";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans += (u + 'a');
        for (auto x : adj[u])
        {
            ind[x]--;
            if (ind[x] == 0)
            {
                q.push(x);
            }
        }
    }
    if (ans.size() != 26)
    {
        cout << "Impossible";
    }
    else
    {
        cout << ans;
    }

    return 0;
}