#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int solve(string &s, int idx, int tight, int cnt) {
    if (idx == (int)s.size()) return cnt;

    if (dp[idx][tight][cnt] != -1) 
        return dp[idx][tight][cnt];

    int limit = (tight ? s[idx] - '0' : 9);
    int ans = 0;

    for (int d = 0; d <= limit; d++) {
        int updcnt = cnt + (d == 3 ? 1 : 0);
        ans += solve(s, idx + 1, tight && (d == limit), updcnt);
    }
    return dp[idx][tight][cnt] = ans;
}

int count3(long long x) {
    if (x < 0) return 0;
    string s = to_string(x);
    dp.assign(20, vector<vector<int>>(2, vector<int>(20, -1)));
    return solve(s, 0, 1, 0);
}

int main() {
    long long l, r;
    cin >> l >> r;
    cout << "ans: " << count3(r) - count3(l - 1) << "\n";
    return 0;
}
