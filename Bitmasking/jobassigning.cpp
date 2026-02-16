#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> c;
vector<vector<ll>> dp;

ll solve(int idx, int mask) {
    if (idx == n) return 0;

    if (dp[idx][mask] != -1) return dp[idx][mask];

    ll best = LLONG_MAX;

    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
            ll sub = solve(idx + 1, mask | (1 << j));
            if (sub != LLONG_MAX)
                best = min(best, (ll)c[idx][j] + sub);
        }
    }

    return dp[idx][mask] = best;
}

int main() {
    cin >> n;

    c.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    dp.assign(n, vector<ll>(1 << n, -1));

    cout << solve(0, 0) << "\n";
    return 0;
}
