#include <bits/stdc++.h>
using namespace std;

int dp[20][2][4]; 

int solve(string &s, int idx, int tight, int cnt) {
    if (cnt > 3) return 0;               
    if (idx == (int)s.size()) return 1;   

    int &res = dp[idx][tight][cnt];
    if (res != -1) return res;

    int limit = (tight ? s[idx]-'0' : 9);
    res = 0;
    for (int d=0; d<=limit; d++) {
        int newCnt = cnt + (d != 0 ? 1 : 0);
        res += solve(s, idx+1, tight && (d==limit), newCnt);
    }
    return res;
}

int countClassy(long long x) {
    if (x < 0) return 0;
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        cout << countClassy(r) - countClassy(l-1) << "\n";
    }
    return 0;
}
