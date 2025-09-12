#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> dp;
int n;

int solve(int mask) {
    if (mask == (1<<n) - 1) return 0;     // all jobs assigned
    if (dp[mask] != -1) return dp[mask];

    int worker = __builtin_popcount(mask); // next worker index
    int ans = INT_MAX;

    for (int j = 0; j < n; j++) {
        if (!(mask & (1<<j))) { // job j not assigned
            ans = min(ans, c[worker][j] + solve(mask | (1<<j)));
        }
    }
    return dp[mask] = ans;
}

int main() {
    cin >> n;
    dp.resize(1<<n, -1);  // allocate for all masks
    c.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << solve(0) << endl;
    return 0;
}
