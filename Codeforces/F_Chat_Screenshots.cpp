#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n + 1);
        vector<int> ind(n + 1, 0);

        for (int i = 0; i < k; i++) {
            vector<int> v(n);
            for (int j = 0; j < n; j++)
                cin >> v[j];

            for (int j = 1; j < n - 1; j++) {
                int u = v[j];
                int w = v[j + 1];
                adj[u].push_back(w);
            }
        }

        
        for (int i = 1; i <= n; i++)
            for (int w : adj[i])
                ind[w]++;

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (ind[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int w : adj[u]) {
                ind[w]--;
                if (ind[w] == 0)
                    q.push(w);
            }
        }

        cout << (count == n ? "YES\n" : "NO\n");
    }

    return 0;
}
