#include <bits/stdc++.h>
using namespace std;

vector<int> lvl, par;
vector<vector<int>> adj;

void dfs(int node,  int l) {
    lvl[node] = l;
    
    for (auto it : adj[node]) {
          par[it]=node;
         // avoid going back
            dfs(it,l + 1);
        
    }
}

int query(int x, int y) {
    // lift deeper node up
    while (lvl[x] > lvl[y]) x = par[x];
    while (lvl[y] > lvl[x]) y = par[y];

    // move both until common parent
    while (x != y) {
        x = par[x];
        y = par[y];
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    lvl.resize(n + 1);
    par.resize(n + 1,-1);
    adj.resize(n + 1);

    // input: for each node, number of children + list of children
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        adj[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

  
    dfs(1,  0);

    int q;
    cin >> q;
    while (q--) {
        int l, h;
        cin >> l >> h;
        cout << query(l, h) << "\n";
    }
    return 0;
}
