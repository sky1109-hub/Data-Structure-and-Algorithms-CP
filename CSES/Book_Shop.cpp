#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mp;
    cin >> n >> mp;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<vector<int>> dp(n + 1, vector<int>(mp + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mp; j++) {
            int nt = dp[i - 1][j]; 
            int t = 0;
            if (c[i - 1] <= j) {
                t = p[i - 1] + dp[i - 1][j - c[i - 1]];  
            }
            dp[i][j] = max(nt, t);
        }
    }

    cout << dp[n][mp] << "\n";
    return 0;
}
