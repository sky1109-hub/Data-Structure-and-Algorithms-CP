#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<int>> dp;

int solve(int idx, int cnt, int k, int n) {
    if (cnt == k) return 1;

    if (dp[idx][cnt] != -1)
        return dp[idx][cnt];

    int ans = 0;

    // iterate only through multiples of idx
    for (int i = idx; i <= n; i += idx) {
        ans += solve(i, cnt + 1, k, n);
        if (ans >= MOD) ans -= MOD;
    }

    return dp[idx][cnt] = ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    dp.assign(n + 1, vector<int>(k + 1, -1));

    int ans = 0;

    // first element of sequence can be anything from 1..n
    for (int i = 1; i <= n; i++) {
        ans += solve(i, 1, k, n);
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << endl;
    return 0;
}
