#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> dp(n, vector<int>(s + 1, 0));

    for (int t = 0; t <= s; t++) {
        if (t % c[0] == 0) dp[0][t] = t / c[0];
        else dp[0][t] = INT_MAX;
    }

  
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= s; t++) {
            int nt = dp[i - 1][t]; 
            int take = INT_MAX;
            if (t >= c[i] && dp[i][t - c[i]] != INT_MAX) {
                take = 1 + dp[i][t - c[i]];
            }
            dp[i][t] = min(nt, take);
        }
    }

    if (dp[n - 1][s] == INT_MAX) cout << -1;
    else cout << dp[n - 1][s];
    return 0;
}
