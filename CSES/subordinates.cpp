#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> sub;

int dfs(int u) {
    int size = 1;
    for(int v : g[u]) {
        size += dfs(v);
    }
    sub[u] = size;
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    g.resize(n+1);
    sub.resize(n+1);

    for(int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        g[boss].push_back(i);   
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << sub[i] - 1 << " "; // exclude self

    return 0;
}
