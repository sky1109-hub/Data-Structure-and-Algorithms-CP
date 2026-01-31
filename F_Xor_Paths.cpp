#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll k;
vector<vector<ll>> a;
map<ll,ll> L[31][31], R[31][31];
int mid;

void dfs1(int i, int j, int steps, ll xr) {
    if (i >= n || j >= m) return;
    xr ^= a[i][j];
    if (steps == mid) {
        L[i][j][xr]++;
        return;
    }
    dfs1(i+1, j, steps+1, xr);
    dfs1(i, j+1, steps+1, xr);
}

void dfs2(int i, int j, int steps, ll xr) {
    if (i < 0 || j < 0) return;
    xr ^= a[i][j];
    if (steps == (n + m - 2 - mid)) {
        R[i][j][xr]++;
        return;
    }
    dfs2(i-1, j, steps+1, xr);
    dfs2(i, j-1, steps+1, xr);
}

int main() {
    cin >> n >> m >> k;
    a.resize(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    mid = (n + m - 2) / 2;

    dfs1(0, 0, 0, 0);
    dfs2(n-1, m-1, 0, 0);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j != mid) continue;
            for (auto &[x1, c1] : L[i][j]) {
                ll need = k ^ x1 ^ a[i][j];
                if (R[i][j].count(need))
                    ans += c1 * R[i][j][need];
            }
        }
    }

    cout << ans << "\n";
}
