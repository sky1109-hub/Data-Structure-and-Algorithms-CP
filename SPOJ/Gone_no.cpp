#include <bits/stdc++.h>
using namespace std;

vector<int> prime(200, 1);  

void primef(int n) {
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int dp[20][2][200]; 

int solve(string &s, int idx, int tight, int cs) {
    if (idx == s.size()) {
        return prime[cs] ? 1 : 0;
    }
    if (dp[idx][tight][cs] != -1) return dp[idx][tight][cs];

    int limit = (tight ? s[idx]-'0' : 9);
    int ans = 0;

    for (int d = 0; d <= limit; d++) {
        ans += solve(s, idx+1, tight && (d == limit), cs + d);
    }

    return dp[idx][tight][cs] = ans;
}

int helper(int x) {
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0);
}

int main() {
    primef(200);

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << helper(r) - helper(l-1) << "\n";
    }
    return 0;
}
