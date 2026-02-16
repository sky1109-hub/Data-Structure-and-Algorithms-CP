#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, ans;
vector<vector<int>> dp;

int lcs(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    a.resize(m), b.resize(n);
    dp.resize(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << lcs(m, n) << endl;

   
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
