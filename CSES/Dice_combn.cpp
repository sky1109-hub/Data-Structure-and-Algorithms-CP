#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int n, vector<int>& dp) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    long long s = 0;
    for (int i = 1; i <= min(n, 6); i++) {
        s = (s + solve(n - i, dp)) % mod;
    }

    return dp[n] = s;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp) << endl;
    return 0;
}
